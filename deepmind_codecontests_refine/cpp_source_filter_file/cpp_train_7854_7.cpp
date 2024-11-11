#include <bits/stdc++.h>
using namespace std;
int n;
pair<int, int> dates[5005];
bool ok(int threshold) {
  int min_date = 0;
  for (int i = 1; i <= n; i++) {
    if (dates[i].second >= min_date) {
      min_date = dates[i].second;
    } else if (dates[i].first >= min_date) {
      min_date = dates[i].first;
    }
    if (min_date > threshold) return false;
  }
  return true;
}
int solve() {
  int left = dates[1].second, right = dates[n].first;
  while (left + 1 < right) {
    int mid = (left + right) / 2;
    if (ok(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  return right;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> dates[i].first >> dates[i].second;
  }
  sort(dates + 1, dates + 1 + n);
  cout << solve() << endl;
  return 0;
}
