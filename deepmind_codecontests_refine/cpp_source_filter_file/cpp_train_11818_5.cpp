#include <bits/stdc++.h>
using namespace std;
const size_t MAX_BEACONS = 100000;
pair<int, int> beacon[MAX_BEACONS];
int dp[MAX_BEACONS];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> beacon[i].first >> beacon[i].second;
  }
  sort(beacon, beacon + n);
  int maxSurvivors = 0;
  dp[0] = 1;
  for (int lastBeacon = 1; lastBeacon < n; ++lastBeacon) {
    int leftmostDestroyPos =
        beacon[lastBeacon].first - beacon[lastBeacon].second;
    int l = -1, r = lastBeacon - 1;
    while (l < r) {
      int mid = (l + r + 1) / 2;
      if (beacon[mid].first < leftmostDestroyPos) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    int leftmostSurvivor = l;
    int survivors = 1;
    if (l != -1) {
      survivors += dp[leftmostSurvivor];
    }
    if (survivors > maxSurvivors) maxSurvivors = survivors;
    dp[lastBeacon] = survivors;
  }
  cout << n - maxSurvivors << endl;
  return 0;
}
