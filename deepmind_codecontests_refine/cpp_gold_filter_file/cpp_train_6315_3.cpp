#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<pair<pair<long long, long long>, pair<long long, long long>>> days(n +
                                                                            1);
  vector<long long> s(n + 1);
  vector<long long> d(n + 1);
  vector<long long> c(n + 1);
  for (int i = 0; i < (n); i++) days[i + 1] = {{-1, -1}, {-1, -1}};
  for (int i = 0; i < (m); i++) {
    cin >> s[i + 1] >> d[i + 1] >> c[i + 1];
    days[d[i + 1]] = {{i + 1, c[i + 1]}, {s[i + 1], d[i + 1]}};
  }
  vector<long long> result(n + 1);
  vector<pair<pair<long long, long long>, pair<long long, long long>>> actions;
  bool succ = true;
  for (int i = n; i >= 1; i--) {
    if (days[i].first.first != -1) {
      result[i] = m + 1;
      actions.push_back(days[i]);
    } else {
      long long learning_day = 0;
      long long best = 102;
      for (int j = 0; j < (actions.size()); j++) {
        long long start = actions[j].second.first;
        long long end = actions[j].second.second;
        long long cc = actions[j].first.second;
        long long day = actions[j].first.first;
        long long local_cost = (i - start + 1) - cc;
        if (best > local_cost) {
          best = local_cost;
          learning_day = day;
        }
        if (cc > (i - start + 1)) {
          succ = false;
          break;
        }
      }
      if (succ) {
        result[i] = learning_day;
        if (best < 102) {
          long long to_erase = -1;
          for (int j = 0; j < (actions.size()); j++) {
            long long day = actions[j].first.first;
            if (day == learning_day) {
              actions[j].first.second--;
              if (actions[j].first.second <= 0) {
                to_erase = j;
                break;
              }
            }
          }
          if (to_erase >= 0) actions.erase(actions.begin() + to_erase);
        }
      } else {
        break;
      }
    }
  }
  if (succ && actions.size() == 0) {
    for (int i = 0; i < (n); i++) cout << result[i + 1] << " ";
    cout << endl;
  } else
    cout << -1 << endl;
}
