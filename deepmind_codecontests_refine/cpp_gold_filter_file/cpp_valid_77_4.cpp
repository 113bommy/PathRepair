#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("tune=native")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int MAX = 4e6 + 5;
const long long MOD = 1000000007;
const long long MOD2 = 2010405347;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 315;
inline long long pw(long long x, long long y, long long md = MOD) {
  long long ret = 1;
  x %= md;
  while (y) {
    if (y & 1) ret = ret * x % md;
    x = x * x % md, y >>= 1;
  }
  return ret;
}
inline void add(int &a, int b, int md = MOD) {
  a = a + b >= md ? a + b - md : a + b;
}
long long n, md, sm, nw, z;
int x[MAX], y[MAX], cnt, tmp, bg[MAX], k;
vector<pair<int, int> > v;
bitset<MAX> p;
void gen(int nw, int o) {
  if (nw == v.size()) {
    if (o != 1) z += x[y[o] + 1] - x[y[o]], ++y[o];
    return;
  }
  gen(nw + 1, o);
  for (int i = (1); i <= (v[nw].second); ++i) {
    o *= v[nw].first;
    gen(nw + 1, o);
  }
  return;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  for (int i = (2); i < (MAX); ++i)
    if (!p[i]) {
      for (int j = i; j < MAX; j += i) {
        p[j] = 1;
        bg[j] = i;
      }
    }
  cin >> n >> md;
  x[1] = sm = 1;
  for (int i = (2); i <= (n); ++i) {
    tmp = i;
    v.clear();
    while (tmp != 1) {
      cnt = 0, k = bg[tmp];
      while (tmp % k == 0) tmp /= k, ++cnt;
      v.push_back({k, cnt});
    }
    gen(0, 1);
    z %= md;
    x[i] = (sm + z) % md;
    sm = (sm + x[i]) % md;
  }
  cout << (x[n] % md + md) % md << '\n';
  return 0;
}
