#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m, k, q;
  cin >> n >> m >> k >> q;
  int tv[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      tv[i][j] = -1;
    }
  }
  for (int i = 0; i < q; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    tv[x - 1][y - 1] = t;
  }
  int vals[n][m];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      vals[i][j] = -1;
    }
  }
  for (int i = 0; i < n; i++) {
    int counter = 0;
    deque<int> times;
    for (int j = 0; j < m; j++) {
      if (tv[i][j] == -1) {
        counter = 0;
        times.clear();
      } else {
        counter++;
        int currtime = tv[i][j];
        while (!times.empty() && times.back() < currtime) {
          times.pop_back();
        }
        times.push_back(currtime);
        if (counter >= k) {
          vals[i][j] = times.front();
          if (times.front() == tv[i][j - k + 1]) {
            times.pop_front();
          }
        }
      }
    }
  }
  int broken = -1;
  for (int j = 0; j < m; j++) {
    int counter = 0;
    deque<int> times;
    for (int i = 0; i < n; i++) {
      if (vals[i][j] == -1) {
        counter = 0;
        times.clear();
      } else {
        counter++;
        int currtime = vals[i][j];
        while (!times.empty() && times.back() < currtime) {
          times.pop_back();
        }
        times.push_back(currtime);
        if (counter >= k) {
          if (times.front() < broken || broken == -1) {
            broken = times.front();
          }
          if (times.front() == vals[i - k + 1][j]) {
            times.pop_front();
          }
        }
      }
    }
  }
  cout << broken << endl;
}
