#include <bits/stdc++.h>
using namespace std;
const int M = 15, N = 15;
int m, n;
pair<int, int> a[M], b[N];
vector<int> tot, cur;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> a[i].first >> a[i].second;
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i].first >> b[i].second;
  }
  for (int i = 1; i <= m; i++) {
    cur.clear();
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      if (a[i].first == b[j].first || a[i].first == b[j].second) {
        cnt++;
      }
      if (a[i].second == b[j].first || a[i].second == b[j].second) {
        cnt++;
      }
      if (cnt == 1) {
        if (a[i].first == b[j].first || a[i].first == b[j].second) {
          cur.push_back(a[i].first);
        } else {
          cur.push_back(a[i].second);
        }
      }
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    if (cur.size() >= 2) {
      return cout << -1, 0;
    } else if (cur.size() == 1) {
      tot.push_back(cur[0]);
    }
  }
  for (int i = 1; i <= n; i++) {
    cur.clear();
    for (int j = 1; j <= m; j++) {
      int cnt = 0;
      if (b[i].first == a[j].first || b[i].first == a[j].second) {
        cnt++;
      }
      if (b[i].second == a[j].first || b[i].second == a[j].second) {
        cnt++;
      }
      if (cnt == 1) {
        if (b[i].first == a[j].first || b[i].first == a[j].second) {
          cur.push_back(b[i].first);
        } else {
          cur.push_back(b[i].second);
        }
      }
    }
    sort(cur.begin(), cur.end());
    cur.erase(unique(cur.begin(), cur.end()), cur.end());
    if (cur.size() >= 2) {
      return cout << -1, 0;
    } else if (cur.size() == 1) {
      tot.push_back(cur[0]);
    }
  }
  sort(tot.begin(), tot.end());
  tot.erase(unique(tot.begin(), tot.end()), tot.end());
  if (tot.size() >= 2) {
    cout << 0;
  } else {
    cout << 1;
  }
}
