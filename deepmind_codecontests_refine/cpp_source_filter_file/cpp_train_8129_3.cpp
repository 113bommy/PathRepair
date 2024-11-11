#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
inline void add(int &x, int y) {
  x += y;
  if (x >= mod) x -= y;
}
inline int mul(int a, int b) { return (long long)a * b % mod; }
inline int Pow(int a, int p) {
  int ret = 1;
  while (p) {
    if (p & 1) ret = (long long)ret * a % mod;
    a = (long long)a * a % mod;
    p >>= 1;
  }
  return ret;
}
int n, m;
int main(int argc, char const *argv[]) {
  scanf("%d %d", &n, &m);
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < n; ++i) {
    for (int j = 0, a; j < m; ++j) {
      scanf("%d", &a);
      v.push_back({a, {i, j}});
    }
  }
  int r, c;
  scanf("%d %d", &r, &c);
  --r, --c;
  sort(v.begin(), v.end());
  int sum = 0;
  int sx = 0;
  int sy = 0;
  for (int i = 0, j; i < v.size(); i = j) {
    j = i + 1;
    while (j < v.size() && v[j].first == v[i].first) ++j;
    int tsx = 0;
    int tsy = 0;
    int tsum = 0;
    for (int k = i; k < j; ++k) {
      int x = v[k].second.first;
      int y = v[k].second.second;
      int E =
          sum + mul(i, mul(x, x) + mul(y, y)) - mul(2, mul(x, sx) + mul(y, sy));
      E %= mod;
      if (E < 0) E += mod;
      E = mul(E, Pow(i, mod - 2));
      add(tsum, E);
      add(sum, mul(x, x));
      add(sum, mul(y, y));
      add(tsx, x);
      add(tsy, y);
      if (x == r && y == c) {
        printf("%d\n", E);
        return 0;
      }
    }
    add(sum, tsum);
    add(sx, tsx);
    add(sy, tsy);
  }
}
