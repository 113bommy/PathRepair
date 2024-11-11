#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007;
const int INF = 1000000001;
const long long LINF = 1000000000000000001LL;
int maxDist(vector<int> &x) {
  int ans = 0;
  for (int i = (0); i <= ((int)(x).size() - 2); ++i) {
    ans = max(ans, x[i + 1] - x[i]);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pair<int, char>> pts(n);
  vector<int> greens;
  for (int i = (0); i <= (n - 1); ++i) {
    cin >> pts[i].first >> pts[i].second;
    if (pts[i].second == 'G') {
      greens.push_back(i);
    }
  }
  int minRed = INF, maxRed = 0;
  int minBlue = INF, maxBlue = 0;
  for (auto &e : pts) {
    if (e.second == 'R') {
      minRed = min(minRed, e.first);
      maxRed = max(maxRed, e.first);
    } else if (e.second == 'B') {
      minBlue = min(minBlue, e.first);
      maxBlue = max(maxBlue, e.first);
    }
  }
  long long ans = 0;
  if (greens.empty()) {
    if (minRed < INF) {
      ans += maxRed - minRed;
    }
    if (minBlue < INF) {
      ans += maxBlue - minBlue;
    }
  } else {
    int m = greens.size();
    int first = pts[greens[0]].first;
    int last = pts[greens[m - 1]].first;
    if (minRed < first) {
      ans += first - minRed;
    }
    if (maxRed > last) {
      ans += maxRed - last;
    }
    if (minBlue < first) {
      ans += first - minBlue;
    }
    if (maxBlue > last) {
      ans += maxBlue - last;
    }
    for (int i = (0); i <= (m - 2); ++i) {
      int l = greens[i];
      int r = greens[i + 1];
      int posLeft = pts[l].first;
      int posRight = pts[r].first;
      int len = posRight - posLeft;
      vector<int> blue = {posLeft};
      vector<int> red = {posLeft};
      for (int j = (l + 1); j <= (r - 1); ++j) {
        if (pts[j].second == 'B') {
          blue.push_back(pts[j].first);
        } else {
          red.push_back(pts[j].first);
        }
      }
      if (blue.size() == 1 && red.size() == 1) {
        ans += len;
      } else {
        blue.push_back(posRight);
        red.push_back(posRight);
        int distBlue = maxDist(blue);
        int distRed = maxDist(red);
        long long opt1 = 2LL * len;
        long long opt2 = 3LL * len - distBlue - distRed;
        ans += min(opt1, opt2);
      }
    }
  }
  cout << ans;
  return 0;
}
