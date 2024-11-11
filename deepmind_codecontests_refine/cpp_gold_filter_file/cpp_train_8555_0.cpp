#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;
long long get_val(long long num) { return num & (-num); }
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m;
  cin >> n >> m;
  vector<int> v[n + 1];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    v[a].push_back(b);
    v[b].push_back(a);
  }
  if (n <= 6)
    cout << m << "\n";
  else {
    int ans = INT_MAX;
    for (int i = 1; i <= n; i++) {
      for (int j = i + 1; j <= n; j++) {
        map<int, int> mp;
        int cnt = 0;
        for (auto k : v[i]) mp[k]++;
        for (auto k : v[j]) {
          mp[k]++;
          if (mp[k] == 2) cnt++;
        }
        ans = min(ans, cnt);
      }
    }
    cout << m - ans;
  }
  return 0;
}
