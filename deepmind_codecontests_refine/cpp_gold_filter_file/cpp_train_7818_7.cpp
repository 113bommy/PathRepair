#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
long long __gcd(long long a, long long b) {
  if (b == 0) return a;
  return __gcd(b, a % b);
}
int main() {
  std ::ios_base ::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  int n, m;
  cin >> n >> m;
  vector<vector<pair<int, int> > > adj(n, vector<pair<int, int> >());
  for (int i = 0; i < n; ++i) adj[i].push_back(make_pair(i + 1, i + 1));
  int curr = n + 1;
  int x, y;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    x--, y--;
    adj[x].push_back(make_pair(x + 1, curr));
    adj[y].push_back(make_pair(y + 1, curr));
    curr++;
  }
  for (int i = 0; i < n; ++i) {
    cout << adj[i].size() << endl;
    for (auto it : adj[i]) cout << it.first << " " << it.second << endl;
  }
}
