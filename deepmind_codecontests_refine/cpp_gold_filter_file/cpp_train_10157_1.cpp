#include <bits/stdc++.h>
using namespace std;
struct team_t {
  int id, points, delta;
  bool operator<(team_t t) const {
    return points != t.points ? points > t.points : id < t.id;
  }
};
int main() {
  int n;
  cin >> n;
  vector<team_t> teams(n);
  for (int i = 0; i < n; i++) {
    teams[i].id = i;
    cin >> teams[i].points >> teams[i].delta;
  }
  sort((teams).begin(), (teams).end());
  int ans = 0;
  for (int i = 0; i < n;) {
    int delta = 0;
    if (teams[i].delta < 0) {
      teams[i].points += teams[i].delta;
      teams[i].delta = 0;
      team_t team_i = teams[i];
      sort((teams).begin(), (teams).end());
      delta = lower_bound((teams).begin(), (teams).end(), team_i) -
              teams.begin() - i;
      ans += delta;
    }
    if (!delta) {
      i++;
    }
  }
  for (int i = n - 1; i >= 0;) {
    int delta = 0;
    if (teams[i].delta > 0) {
      teams[i].points += teams[i].delta;
      teams[i].delta = 0;
      team_t team_i = teams[i];
      sort((teams).begin(), (teams).end());
      delta = lower_bound((teams).begin(), (teams).end(), team_i) -
              teams.begin() - i;
      ans -= delta;
    }
    if (!delta) {
      i--;
    }
  }
  cout << ans;
}
