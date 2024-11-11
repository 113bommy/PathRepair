#include <bits/stdc++.h>
using namespace std;
const int maxn = 700000 + 50;
const long long Mod = 1000000000 + 7;
struct node1 {
  long long v;
  int id, k;
  bool operator<(const node1 i) const { return v < i.v; }
} a[maxn];
long long Pow(long long A, long long B) {
  A %= Mod;
  B %= Mod;
  long long Ans = 1;
  while (B) {
    if (B & 1) Ans = Ans * A % Mod;
    A = A * A % Mod;
    B >>= 1;
  }
  return Ans;
}
int n, Q, k;
long long p[maxn], inv[maxn], val, D[maxn];
int b[maxn], c[maxn];
struct node {
  long long sum1, sum2, Ans, sum3;
} T[maxn * 4];
void update(int root, int l, int r) {
  int mid = (l + r) >> 1;
  T[root].sum1 %= Mod;
  T[root].sum2 %= Mod;
  T[root].sum3 %= Mod;
  T[root].Ans = (T[root << 1].Ans * p[T[root << 1 | 1].sum3] % Mod +
                 T[root << 1 | 1].Ans * p[T[root << 1].sum3] % Mod) %
                Mod;
  T[root].Ans =
      (T[root].Ans + (((T[root << 1].sum1 * T[root << 1 | 1].sum2) % Mod) *
                      p[T[root << 1].sum3]) %
                         Mod) %
      Mod;
  T[root].sum1 = (T[root << 1].sum1 * inv[T[root << 1 | 1].sum3] % Mod +
                  T[root << 1 | 1].sum1) %
                 Mod;
  T[root].sum2 = (T[root << 1].sum2 * p[T[root << 1 | 1].sum3] % Mod +
                  T[root << 1 | 1].sum2) %
                 Mod;
  T[root].sum3 = T[root << 1].sum3 + T[root << 1 | 1].sum3;
}
void build(int root, int l, int r) {
  if (l == r) {
    T[root].Ans = 0;
    T[root].sum1 = D[l] * inv[1];
    T[root].sum2 = D[l];
    T[root].sum3 = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  build(root << 1, l, mid);
  build(root << 1 | 1, mid + 1, r);
  update(root, l, r);
}
void modify(int root, int l, int r, int k, long long val) {
  if (l == r) {
    D[l] = val % Mod;
    T[root].Ans = 0;
    T[root].sum1 = D[l] * inv[1] % Mod;
    T[root].sum2 = D[l] % Mod;
    T[root].sum3 = c[l];
    return;
  }
  int mid = (l + r) >> 1;
  if (k <= mid)
    modify(root << 1, l, mid, k, val);
  else
    modify(root << 1 | 1, mid + 1, r, k, val);
  update(root, l, r);
}
int main() {
  cin >> n;
  inv[0] = 1;
  p[0] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i].v);
    a[i].id = i;
  }
  cin >> Q;
  for (int i = 1; i <= Q; i++) {
    scanf("%d %lld", &k, &val);
    a[i + n].v = val;
    a[i + n].id = i + n;
    a[i + n].k = k;
  }
  sort(a + 1, a + n + Q + 1);
  for (int i = 1; i <= n + Q; i++) {
    b[a[i].id] = i;
    if (a[i].id <= n) c[i] = 1, D[i] = a[i].v;
  }
  for (int i = 1; i <= n + Q; i++) {
    inv[i] = Pow(Pow(2, i), Mod - 2) % Mod;
    p[i] = p[i - 1] * 2 % Mod;
  }
  build(1, 1, n + Q);
  cout << T[1].Ans * inv[n] % Mod << endl;
  for (int i = n + 1; i <= n + Q; i++) {
    k = a[b[i]].k;
    val = a[b[i]].v;
    c[b[k]] = 0;
    modify(1, 1, n + Q, b[k], 0);
    c[b[i]] = 1;
    modify(1, 1, n + Q, b[i], val);
    b[k] = b[i];
    printf("%lld\n", T[1].Ans * inv[n] % Mod);
  }
  return 0;
}
