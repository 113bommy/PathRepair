#include <bits/stdc++.h>
using namespace std;
const long long N = 4e6 + 20;
const long long M = 1e7 + 20;
const long long MOD = 1e9 + 7;
const long long Inf = 1e18;
const long double eps = 1e-7;
const long long dx[] = {1, 0, -1, 0};
const long long dy[] = {0, 1, 0, -1};
long long n, m, x, a[N], Ans[N], y, z, q, k, timer, tt = 1;
void Solve() {
  for (long long i = 0; i <= n + 1; ++i) Ans[i] = 0;
  long long cnt = 0;
  string s;
  scanf("%lld", &n);
  for (long long i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  cin >> s;
  vector<pair<long long, long long> > Vec1, Vec2;
  for (long long i = 0; i < s.size(); ++i)
    if (s[i] == '1') {
      ++cnt;
      Vec1.push_back({a[i + 1], i + 1});
    } else
      Vec2.push_back({a[i + 1], i + 1});
  sort(Vec1.begin(), Vec1.end());
  sort(Vec2.begin(), Vec2.end());
  long long G = n - cnt + 1;
  for (auto x : Vec1) Ans[x.second] = G++;
  G = 1;
  for (auto x : Vec2) Ans[x.second] = G++;
  for (long long i = 1; i <= n; ++i) cout << Ans[i] << " \n"[i == n];
}
int main() {
  scanf("%lld", &tt);
  while (tt--) {
    ++timer;
    Solve();
  }
}
