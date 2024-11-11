#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long m, n;
  cin >> m >> n;
  long long x, y;
  map<long long, long long> mp[m + 5];
  std::vector<long long> sz(m + 5, 0);
  long long ans = 1;
  for (long long i = 0; i < m; i++) {
    cin >> x;
    std::vector<long long> v;
    for (long long j = 0; j < x; j++) {
      cin >> y;
      mp[i][y] = 1;
    }
    sz[i] = x;
    for (long long j = 1; j <= n; j++) {
      if (mp[i][j] == 0) v.push_back(j);
    }
    long long cnt = 0;
    for (long long j = i - 1; j >= 0; j--) {
      cnt = 0;
      for (long long k = 0; k < v.size(); k++) {
        if (mp[j][v[k]] == 1) cnt++;
      }
      if (cnt == sz[j]) ans = 0;
    }
  }
  if (ans == 0)
    cout << "impossible";
  else
    cout << "possible";
  return 0;
}
