#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int x[n];
    for (int i = 0; i < n; i++) cin >> x[i];
    string s[n];
    for (int i = 0; i < n; i++) cin >> s[i];
    int ans[m], score = -1;
    for (int i = 0; i < (1 << n); i++) {
      vector<pair<int, int> > vt;
      for (int j = 0; j < m; j++) {
        int cnt = 0;
        for (int k = 0; k < n; k++) {
          if (s[k][j] == '1') {
            if (i & (1 << k))
              cnt++;
            else
              cnt--;
          }
        }
        vt.push_back(make_pair(cnt, j));
      }
      sort(vt.begin(), vt.end());
      int temp[m], curr_score = 0;
      for (int j = 0; j < m; j++) {
        int idx = vt[j].second;
        temp[idx] = j + 1;
      }
      for (int j = 0; j < n; j++) {
        int sum = 0;
        for (int k = 0; k < m; k++) sum += (s[j][k] - '0') * temp[k];
        curr_score += abs(sum - x[j]);
      }
      if (curr_score > score) {
        score = curr_score;
        for (int j = 0; j < m; j++) ans[j] = temp[j];
      }
    }
    for (int i = 0; i < m; i++) cout << ans[i] << ' ';
    cout << '\n';
  }
}
