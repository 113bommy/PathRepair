#include <bits/stdc++.h>
using namespace std;
template <typename T>
void pv(T a, T b) {
  for (T i = a; i <= b; ++i) cout << *i << " ";
  cout << endl;
}
template <typename T>
void chmin(T &t, const T &f) {
  if (t > f) t = f;
}
template <typename T>
void chmax(T &t, const T &f) {
  if (t < f) t = f;
}
template <typename T>
T in() {
  T x = 0;
  T p = 1;
  char c;
  do {
    c = getchar();
  } while (c <= 32);
  if (c == '-') {
    p = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + c - 48;
    c = getchar();
  }
  return x * p;
}
const int LIM = 200000;
int n, m, i, x, y, fa[LIM];
long long ans;
const long long MOD = (long long)1e9 + 9LL;
int F(int x) { return (x == fa[x] ? x : fa[x] = F(fa[x])); }
void U(int x, int y) { fa[F(y)] = F(x); }
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  ans = 1LL;
  for (i = 1; i <= m; ++i) {
    cin >> x >> y;
    if (F(x) == F(y)) {
      ans = (2LL * ans) % MOD;
    } else
      U(x, y);
    cout << ((ans - 1) % MOD + MOD) % MOD << "\n";
  }
  return 0;
}
