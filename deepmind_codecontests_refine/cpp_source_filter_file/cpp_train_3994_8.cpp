#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
inline long long int input() {
  long long int n;
  cin >> n;
  return n;
}
long long int poww(long long int a, long long int b, long long int md) {
  return (!b ? 1
             : (b & 1 ? a * poww(a * a % md, b / 2, md) % md
                      : poww(a * a % md, b / 2, md) % md));
}
const long long int MAXN = 2e5 + 10;
const long long int MAXA = 101;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
const long double PI = 4 * atan((long double)1);
long long int a[MAXN];
set<long long int> s;
map<long long int, long long int> mp;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
  ;
  long long int n, k;
  cin >> n >> k;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int ind = 0, r;
  for (long long int i = 0; i < n; i++) {
    mp[a[i]]++;
    if ((long long int)mp.size() >= k) {
      r = i + 1;
      break;
    }
  }
  if ((long long int)mp.size() < k) return cout << -1 << ' ' << -1 << '\n', 0;
  pair<long long int, long long int> ans = {0, ind - 1};
  long long int l;
  for (long long int i = 0; i < r - 1; i++) {
    if (mp[a[i]] == 1) {
      l = i + 1;
      break;
    }
    mp[a[i]]--;
  }
  cout << l << " " << r << '\n';
  return 0;
}
