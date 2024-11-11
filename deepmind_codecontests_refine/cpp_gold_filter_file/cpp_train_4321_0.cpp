#include <bits/stdc++.h>
using namespace std;
int P;
const int N = 5e5 + 5;
struct Matrix {
  int a[2][2];
  Matrix() { memset(a, 0, sizeof(a)); }
} I;
Matrix operator*(const Matrix &A, const Matrix &B) {
  Matrix C;
  for (int i = 0; i < 2; ++i)
    for (int k = 0; k < 2; ++k)
      for (int j = 0; j < 2; ++j)
        C.a[i][j] = ((long long)A.a[i][k] * B.a[k][j] + C.a[i][j]) % P;
  return C;
}
Matrix find(long long n, Matrix a) {
  Matrix ans = I;
  while (n > 0) {
    if (n & 1) ans = ans * a;
    a = a * a;
    n = n >> 1;
  }
  return ans;
}
Matrix tree[N * 4];
int S[N], n;
void build(int k, int m, int n) {
  if (m == n) {
    tree[k].a[0][0] = 0;
    tree[k].a[0][1] = S[m];
    tree[k].a[1][0] = 1;
    tree[k].a[1][1] = S[m + 1];
    return;
  }
  int mid = (m + n) >> 1, z1 = k << 1, z2 = z1 + 1;
  build(z1, m, mid);
  build(z2, mid + 1, n);
  tree[k] = tree[z1] * tree[z2];
}
pair<long long, int> pr[N];
Matrix search(int k, int m, int n, int l, int r) {
  if (m > r || n < l) return I;
  if (m >= l && n <= r) return tree[k];
  int mid = (m + n) >> 1, z1 = k << 1, z2 = z1 + 1;
  return search(z1, m, mid, l, r) * search(z2, mid + 1, n, l, r);
}
Matrix getmatrix(int l, int r) {
  if (l <= r) return search(1, 0, n - 1, l, r);
  return search(1, 0, n - 1, l, n - 1) * search(1, 0, n - 1, 0, r);
}
Matrix solve(long long x, long long y) {
  if (x == y) return I;
  --y;
  Matrix trans = I;
  Matrix trans1 = getmatrix(x % n, (x + n - 1) % n);
  long long p = (y - x) / n;
  trans = trans * find(p, trans1);
  x += p * n;
  trans = trans * getmatrix(x % n, y % n);
  return trans;
}
int main() {
  long long K;
  scanf("%I64d%d", &K, &P);
  I.a[0][0] = I.a[1][1] = 1 % P;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &S[i]);
    S[i] %= P;
  }
  S[n] = S[0];
  build(1, 0, n - 1);
  int m, r = 0;
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%I64d%d", &pr[i].first, &pr[i].second);
    if (pr[i].first > K) continue;
    pr[i].second %= P;
    pr[++r] = pr[i];
  }
  m = r;
  sort(pr + 1, pr + 1 + m);
  pr[0] = make_pair(0, S[0]);
  if (pr[m].first < K) pr[++m] = make_pair(K, S[K % n]);
  long long pos = 0, F0 = 0, F1 = 1 % P;
  for (int i = 1; i <= m; ++i) {
    Matrix trans;
    if (pr[i].first == pos + 1) {
      trans.a[0][0] = 0;
      trans.a[0][1] = pr[i - 1].second;
      trans.a[1][0] = 1 % P;
      trans.a[1][1] = pr[i].second;
    } else {
      trans.a[0][0] = 0;
      trans.a[0][1] = pr[i - 1].second;
      trans.a[1][0] = 1 % P;
      trans.a[1][1] = S[(pos + 1) % n];
      trans = trans * solve(pos + 1, pr[i].first - 1);
      Matrix trans1;
      pos = pr[i].first - 1;
      trans1.a[0][0] = 0;
      trans1.a[0][1] = S[pos % n];
      trans1.a[1][0] = 1 % P;
      trans1.a[1][1] = pr[i].second;
      trans = trans * trans1;
    }
    pos = pr[i].first;
    long long G0 = F0 * trans.a[0][0] + F1 * trans.a[1][0];
    long long G1 = F0 * trans.a[0][1] + F1 * trans.a[1][1];
    F0 = G0 % P;
    F1 = G1 % P;
  }
  cout << F0 << endl;
  return 0;
}
