#include <bits/stdc++.h>
using namespace std;
long long a[5005][5005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int TESTS = 1;
  while (TESTS--) {
    long long n, m, k, t, x, y;
    cin >> n >> m >> k;
    map<long long, long long> m1, m2;
    vector<pair<long long, pair<long long int, long long int>>> v;
    for (long long int i = 0; i < n; i++) {
      cin >> t >> x >> y;
      v.push_back({t, {x, y}});
    }
    for (long long i = k - 1; i >= 0; i--) {
      if (v[i].first == 1) {
        if (!m1[v[i].second.first]) {
          m1[v[i].second.first] = 1;
          for (long long int j = 1; j < m + 1; j++) {
            if (a[v[i].second.first][j] == 0)
              a[v[i].second.first][j] = v[i].second.second;
          }
        }
      } else {
        if (!m2[v[i].second.first]) {
          m2[v[i].second.first] = 1;
          for (long long int j = 1; j < n + 1; j++) {
            if (a[j][v[i].second.first] == 0)
              a[j][v[i].second.first] = v[i].second.second;
          }
        }
      }
    }
    for (long long int i = 1; i < n + 1; i++) {
      for (long long int j = 1; j < m + 1; j++) cout << a[i][j] << " ";
      cout << '\n';
    }
  }
  return 0;
}
