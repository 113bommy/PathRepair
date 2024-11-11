#include <bits/stdc++.h>
using namespace std;
const int INF = 999999999;
const double EPSILON = 0.00000001;
const long long MOD = 1000000007;
bool used[200005];
struct interval {
  int first, second;
  int idx;
};
bool operator<(const interval &self, const interval &other) {
  return self.first < other.first;
}
int main() {
  int x, n;
  cin >> x >> n;
  vector<interval> intervals;
  for (int i = 0; i < n; i++) {
    int a, l;
    scanf("%d %d", &a, &l);
    intervals.push_back((interval){a, a + l - 1, i + 1});
  }
  memset(used, false, sizeof(used));
  sort(intervals.begin(), intervals.end());
  int i = 0, prev = 0;
  int end = intervals[0].first - 1;
  int best = 0;
  int cnt = 0;
  while (i < n) {
    while (i < n and intervals[i].first <= end + 1) {
      if (intervals[i].second > intervals[best].second) {
        best = i;
      }
      i++;
    }
    if (used[best]) {
      if (i < n) end = intervals[i].first - 1;
    } else {
      end = intervals[best].second;
      used[best] = true;
      cnt++;
    }
  }
  cout << n - cnt << endl;
  bool first = true;
  for (int i = 0; i < n; i++) {
    if (not used[i]) {
      if (not first) putchar(' ');
      printf("%d", intervals[i].idx);
      first = false;
    }
  }
  if (cnt != n) cout << endl;
  return 0;
}
