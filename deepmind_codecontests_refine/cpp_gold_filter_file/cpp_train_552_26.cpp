#include <bits/stdc++.h>
using namespace std;
const int max_n = 50 + 10;
pair<int, int> team[max_n];
bool compare(pair<int, int> a, pair<int, int> b) {
  if (a.first != b.first) return a.first > b.first;
  return a.second < b.second;
}
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> team[i].first >> team[i].second;
  sort(team, team + n, compare);
  int ans = 1, cur = 1;
  for (int i = 1; i < n; i++) {
    if (team[i] != team[i - 1]) {
      if (cur + ans > k) {
        cout << ans << endl;
        return 0;
      }
      cur += ans;
      ans = 1;
    } else
      ans++;
  }
  cout << ans << endl;
  return 0;
}
