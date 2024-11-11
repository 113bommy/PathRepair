#include <bits/stdc++.h>
using namespace std;
bool isPossFirst(vector<long long> armor, long long mid) {
  for (int i = 0; i < armor.size(); i++) {
    if (mid <= armor[i]) return 0;
    mid++;
  }
  return true;
}
pair<long long, long long> findMin(vector<long long> armor) {
  long long l = 0, r = 10000000000;
  long long mid = 0, ans = 10000000000;
  while (l <= r) {
    mid = l + (r - l) / 2;
    if (isPossFirst(armor, mid)) {
      ans = min(ans, mid);
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return {ans, armor.size()};
}
bool isPoss(vector<pair<long long, long long>> minEntry, long long mid) {
  for (int i = 0; i < minEntry.size(); i++) {
    if (minEntry[i].first > mid) return 0;
    mid += minEntry[i].second;
  }
  return 1;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<pair<long long, long long>> minEntry;
    for (int i = 0; i < n; i++) {
      int k;
      cin >> k;
      vector<long long> armor(k);
      for (int j = 0; j < k; j++) {
        cin >> armor[j];
      }
      minEntry.push_back(findMin(armor));
    }
    sort(minEntry.begin(), minEntry.end());
    long long l = 0, r = 10000000000;
    long long mid = 0, ans = 10000000000;
    while (l <= r) {
      mid = l + (r - l) / 2;
      if (isPoss(minEntry, mid)) {
        ans = min(ans, mid);
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
