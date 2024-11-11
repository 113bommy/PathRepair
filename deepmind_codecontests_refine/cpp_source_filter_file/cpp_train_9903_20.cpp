#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<pair<int, int>> s;
  int job[n];
  int ptime[n];
  set<int> last;
  vector<int> jobs[k];
  for (int i = 0; i < n; ++i) {
    cin >> job[i];
  }
  for (int i = 0; i < n; ++i) {
    cin >> ptime[i];
  }
  for (int i = 0; i < n; ++i) {
    jobs[job[i] - 1].push_back(i);
  }
  for (int i = 0; i < k; ++i) {
    if (jobs[i].size() != 0) {
      int m = ptime[jobs[i][0]];
      int ind = jobs[i][0];
      for (int j = 0; j < jobs[i].size(); ++j) {
        if (ptime[jobs[i][j]] > m) {
          m = ptime[jobs[i][j]];
          ind = jobs[i][j];
        }
      }
      last.insert(ind);
    }
  }
  for (int i = 0; i < n; ++i) {
    s.push_back(make_pair(ptime[i], i));
  }
  sort(s.begin(), s.end());
  int ans = 0;
  int i = 0;
  while (i != n && last.size() != k) {
    if (last.count(s[i].second) == 0) {
      ans += ptime[s[i].second];
      last.insert(s[i].second);
    }
    ++i;
  }
  cout << ans;
}
