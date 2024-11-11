#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e17 + 10;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const int base = 131;
const double pi = acos(-1);
map<string, int> ml;
map<int, int> vi;
long long b[N], vis[N], dep[N], num[N], a[N], n, m, k, x, y;
long long ex, ey, cnt, ans, sum, flag, t;
long long nex[N];
vector<int> res, v;
map<string, int> mp;
map<string, int> can;
set<long long> second;
string s[2000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int d;
  cin >> n;
  string ts;
  string res;
  for (int i = 1; i <= n; i++) {
    cin >> ts >> x;
    a[i] = x;
    s[i] = ts;
    mp[ts] += x;
  }
  for (auto x : mp) ans = max(ans, 1ll * x.second);
  for (auto x : mp)
    if (x.second == ans) can[x.first] = 1;
  mp.clear();
  for (int i = 1; i <= n; i++) {
    mp[s[i]] += a[i];
    if (mp[s[i]] == ans && can[s[i]]) {
      res = s[i];
      break;
    }
  }
  cout << res;
}
