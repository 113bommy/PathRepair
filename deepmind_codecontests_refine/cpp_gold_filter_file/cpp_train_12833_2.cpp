#include <bits/stdc++.h>
using namespace std;
int n, q;
int A[100005];
vector<int> prime;
int Sisa[200005];
vector<int> fbase[88];
vector<int> fpow[200005];
const int block = (int)(sqrt(200000));
const int N = 200000;
const int nP = 86;
vector<int> Max[nP + 1];
vector<int> B[nP + 1];
int mo = 1e9 + 7;
const int LN = 100005 * 18 * 2;
int head[100005], idx = 0;
int L[LN], R[LN];
int Mul[LN];
int Last[200005];
int po[100][100];
int lb(int i, int x) {
  return lower_bound(B[i].begin(), B[i].end(), x) - B[i].begin();
}
int ub(int i, int x) {
  return upper_bound(B[i].begin(), B[i].end(), x) - B[i].begin();
}
void build(int i, int p, int s, int e) {
  if (s == e) {
    if (A[B[i][s]] % prime[i] == 0) {
      Max[i][p] = fbase[i][A[B[i][s]] / prime[i] - 1];
    }
    return;
  }
  int m = (s + e) / 2;
  build(i, p + p + 1, s, m);
  build(i, p + p + 2, m + 1, e);
  Max[i][p] = max(Max[i][p + p + 1], Max[i][p + p + 2]);
}
int insert(int p, int s, int e, int x, int v) {
  int id = ++idx;
  L[id] = L[p];
  R[id] = R[p];
  Mul[id] = Mul[p];
  if (s == e) {
    Mul[id] = v;
    return id;
  }
  int m = (s + e) / 2;
  if (x <= m)
    L[id] = insert(L[p], s, m, x, v);
  else
    R[id] = insert(R[p], m + 1, e, x, v);
  Mul[id] = (1LL * Mul[L[id]] * Mul[R[id]]) % mo;
  return id;
}
int query(int p, int s, int e, int l, int r) {
  if (s > r || e < l) {
    return 1;
  }
  if (l <= s && e <= r) {
    return Mul[p];
  }
  int m = (s + e) / 2;
  return (1LL * query(L[p], s, m, l, r) * query(R[p], m + 1, e, l, r)) % mo;
}
int rmq(int i, int p, int s, int e, int l, int r) {
  if (s > r || e < l) return 0;
  if (l <= s && e <= r) return Max[i][p];
  int m = (s + e) / 2;
  return max(rmq(i, p + p + 1, s, m, l, r), rmq(i, p + p + 2, m + 1, e, l, r));
}
int main() {
  for (int i = 1; i <= N; i++) {
    Sisa[i] = i;
  }
  for (int i = 2; i <= block; i++) {
    if (Sisa[i] != i) continue;
    prime.push_back(i);
    int sz = prime.size() - 1;
    for (int j = i; j <= N; j += i) {
      int id = (j / i) - 1;
      fbase[sz].push_back(0);
      while (Sisa[j] % i == 0) {
        fbase[sz].back() += 1;
        Sisa[j] /= i;
      }
      fpow[j].push_back(sz);
    }
  }
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &A[i]);
  for (int i = 0; i < nP; i++) {
    for (int j = 1; j <= n; j++) {
      if (A[j] % prime[i] == 0) {
        B[i].push_back(j);
      }
    }
    Max[i].assign((int)(B[i].size()) * 4 + 5, 0);
    if (!B[i].empty()) build(i, 0, 0, (int)(B[i].size()) - 1);
  }
  Mul[0] = 1;
  for (int i = 1; i <= n; i++) {
    if (Sisa[A[i]] == 1) {
      head[i] = head[i - 1];
    } else {
      int ss = Sisa[A[i]];
      if (Last[ss] > 0) {
        head[i] = insert(head[i - 1], 1, n, Last[ss], 1);
        head[i] = insert(head[i], 1, n, i, ss);
      } else {
        head[i] = insert(head[i - 1], 1, n, i, ss);
      }
      Last[ss] = i;
    }
  }
  for (int i = 0; i < nP; i++) {
    po[i][0] = 1;
    for (int j = 1; j < 100; j++) {
      po[i][j] = (po[i][j - 1] * 1LL * prime[i]) % mo;
    }
  }
  int ans = 0;
  scanf("%d", &q);
  while (q--) {
    int x, y;
    scanf("%d%d", &x, &y);
    x = (x + ans) % n + 1;
    y = (y + ans) % n + 1;
    if (x > y) swap(x, y);
    ans = query(head[y], 1, n, x, y);
    for (int i = 0; i < nP; i++) {
      if (B[i].empty()) continue;
      if (y < B[i][0] || x > B[i].back()) continue;
      int cnt = rmq(i, 0, 0, (int)(B[i].size()) - 1, lb(i, x), ub(i, y) - 1);
      ans = (ans * 1LL * po[i][cnt]) % mo;
    }
    printf("%d\n", ans);
  }
  return 0;
}
