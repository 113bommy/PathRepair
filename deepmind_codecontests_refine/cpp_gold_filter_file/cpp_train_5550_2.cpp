#include <bits/stdc++.h>
using namespace std;
int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int main() {
  int x;
  cin >> x;
  vector<pair<int, int>> vp, team1, team2;
  for (int i = 1; i <= x; i++) {
    int t;
    cin >> t;
    vp.push_back(make_pair(t, i));
  }
  sort(vp.begin(), vp.end());
  int maxx = 0, sum1 = 0, sum2 = 0;
  for (int i = 0; i < x; i++) {
    if (i & 1)
      team1.push_back(vp[i]), maxx = max(maxx, vp[i].first),
                              sum1 += vp[i].first;
    else
      team2.push_back(vp[i]), maxx = max(maxx, vp[i].first),
                              sum2 += vp[i].first;
  }
  int in1 = 0, in2 = team2.size() - 1;
  while (abs(sum1 - sum2) > maxx) {
    if (in1 < team1.size() && in2 >= 0) {
      sum1 -= team1[in1].first + team2[in2].first;
      sum2 += team1[in1].first - team2[in2].first;
      swap(team1[in1++], team2[in2--]);
    } else {
      break;
    }
  }
  cout << team1.size() << endl;
  for (int i = 0; i < team1.size(); i++) {
    cout << team1[i].second << " ";
  }
  cout << endl << team2.size() << endl;
  for (int i = 0; i < team2.size(); i++) {
    cout << team2[i].second << " ";
  }
  return 0;
}
