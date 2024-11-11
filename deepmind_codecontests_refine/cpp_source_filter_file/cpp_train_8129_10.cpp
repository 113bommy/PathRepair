#include <bits/stdc++.h>
using namespace std;
const int N = 1020;
const int Mod = 998244353;
int a[N][N];
int n, m;
int sz, num[N];
vector<pair<int, int> > vec[N];
void add(int &a, long long b) { a = (a + b) % Mod; }
void add(long long &a, long long b) { a = (a + b) % Mod; }
long long mod_pow(long long x, long long n) {
  long long res = 1;
  for (; n > 0; n >>= 1) {
    if (n & 1) res = res * x % Mod;
    x = x * x % Mod;
  }
  return res;
}
int inv(int x) { return mod_pow(x, Mod - 2); }
struct co {
  int x[2];
  co() { x[0] = x[1] = 0; }
  void Add(int a) {
    add(x[0], a);
    add(x[1], 1LL * a * a % Mod);
  }
  int &operator[](int i) { return x[i]; }
};
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      scanf("%d", &a[i][j]);
      num[sz++] = a[i][j];
    }
  int r, c;
  scanf("%d%d", &r, &c);
  sort(num, num + sz);
  sz = unique(num, num + sz) - num;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      int x = lower_bound(num, num + sz, a[i][j]) - num;
      vec[x].push_back(pair<int, int>(i, j));
    }
  co X, Y;
  long long tot = 0;
  int cnt = 0;
  for (int i = 0; i < sz; i++) {
    long long t = 0;
    for (auto p : vec[i]) {
      int x = p.first, y = p.second;
      long long ans = 0;
      if (cnt == 0)
        ans = 0;
      else {
        ans = (1LL * x * x + 1LL * y * y) % Mod;
        add(ans, (tot + X[1] + Y[1] - 2LL * x * X[0] - 2LL * y * Y[0]) % Mod *
                     inv(cnt));
      }
      ans = (ans + Mod) % Mod;
      if (x == r && y == c) {
        printf("%lld\n", ans);
        return 0;
      }
      add(t, ans);
    }
    add(tot, t);
    for (auto p : vec[i]) {
      int x = p.first, y = p.second;
      X.Add(x);
      Y.Add(y);
    }
    cnt += vec[i].size();
  }
}
