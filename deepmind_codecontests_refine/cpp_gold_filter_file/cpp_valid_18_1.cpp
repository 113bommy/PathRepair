#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, k;
  cin >> n >> k;
  vector<vector<int>> v(k, vector<int>(2));
  vector<bool> b(2 * n + 1, false);
  int ans = 0;
  for (int i = 0; i < k; i++) {
    cin >> v[i][0] >> v[i][1];
    if (v[i][0] > v[i][1]) {
      swap(v[i][0], v[i][1]);
    }
    b[v[i][0]] = true;
    b[v[i][1]] = true;
    int s = v[i][0];
    int e = v[i][1];
    int cnt = 0;
    for (int j = 0; j < i; j++) {
      if (s < v[j][0] && e > v[j][0] && e < v[j][1]) {
        ans++;
      } else if (s > v[j][0] && e > v[j][1] && s < v[j][1]) {
        ans++;
      }
    }
  }
  vector<int> pos;
  for (int i = 1; i <= 2 * n; i++) {
    if (b[i] == false) {
      pos.push_back(i);
    }
  }
  for (int i = 0; i < ((int)pos.size()) / 2; i++) {
    int s = pos[i];
    int e = pos[i + n - k];
    int cnt = 0;
    for (int j = 0; j < v.size(); j++) {
      if (s < v[j][0] && e > v[j][0] && e < v[j][1]) {
        ans++;
      } else if (s > v[j][0] && e > v[j][1] && s < v[j][1]) {
        ans++;
      }
    }
    v.push_back({s, e});
  }
  cout << ans << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
