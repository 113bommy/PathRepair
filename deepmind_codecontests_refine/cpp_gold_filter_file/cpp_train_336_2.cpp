#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
using vl = vector<long long>;
using vpll = vector<pll>;
using mll = map<long long, long long>;
using mcl = map<char, long long>;
using msl = map<string, long long>;
using sl = set<long long>;
using sc = set<char>;
using dl = deque<long long>;
const int N = 1e6 + 5;
long long mod = 1e9 + 7;
vl adj[N];
vpll adjc[N];
long long vis[N];
long long arr[N];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long a, b, c, d, n, m, p, x, y, z, i, j, k,
      f = 0, tc, cnt = 0, sum = 0, mul = 1, mi = 1e18, ma = -1e18;
  string str;
  char ch;
  double db;
  long long l, r;
  cin >> n;
  p = 1;
  for (i = 1; i <= n; i++) {
    mul = (mul * i) % mod;
    if (i != n) p = (p * 2) % mod;
  }
  mul = (mod + mul - p) % mod;
  cout << mul << "\n";
  return 0;
}
