#include <bits/stdc++.h>
using namespace std;
long long n, m, k, x, y, v, u, ans;
vector<vector<int> > adj(10005);
bool visited[10005];
map<long long, long long> lf, rt;
map<pair<long long, long long>, long long> mp;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y;
    lf[x]++, rt[y]++, mp[{x, y}]++;
  }
  for (map<long long, long long>::iterator it = lf.begin(); it != lf.end();
       it++) {
    long long tmp = it->second;
    ans += (tmp * (tmp - 1) / 2);
  }
  for (map<long long, long long>::iterator it = rt.begin(); it != rt.end();
       it++) {
    long long tmp = it->second;
    ans += (tmp * (tmp - 1) / 2);
  }
  for (map<pair<long long, long long>, long long>::iterator it = mp.begin();
       it != mp.end(); it++) {
    long long tmp = it->second;
    ans -= (tmp * (tmp - 1) / 2);
  }
  cout << ans << "\n";
  return 0;
}
