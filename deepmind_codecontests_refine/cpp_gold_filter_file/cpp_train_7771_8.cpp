#include <bits/stdc++.h>
using namespace std;
const long double pi = acos(-1);
const long long int mod = 1e9 + 7;
const long long int MAX = INT_MAX;
const long long int MIN = INT_MIN;
bool sortbysec(pair<long long int, long long int> a,
               pair<long long int, long long int> b) {
  return (a.second < b.second);
}
long long int po(long long int a, long long int p) {
  long long int ret = 1;
  while (p) {
    if (p & 1) ret = (ret * a) % mod;
    a = (a * a) % mod;
    p = p >> 1;
  }
  return ret % mod;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  long long int t, n, i, j, k, len, x, y, z, c, f, flag, p, q, mx, mn, l, r,
      sum, ans, tmp, it, pos, avg, m, cnt;
  string s;
  char ch;
  vector<long long int> v;
  vector<pair<long long int, long long int>> vec;
  unordered_map<long long int, long long int> mappu;
  pair<long long int, long long int> pr;
  t = 1;
  while (t--) {
    cin >> n;
    vector<long long int> adj[10000];
    for (i = 0; i < n - 1; i++) {
      cin >> x >> y;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    for (i = 0; i < 10000; i++)
      if (adj[i].size() == 1) ans++;
    cout << ans << "\n";
  }
  return 0;
}
