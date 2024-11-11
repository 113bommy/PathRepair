#include <bits/stdc++.h>
using namespace std;
int arr[200005];
int n, len, k;
long long solve() {
  int lo = 0, hi = len - 1;
  long long sum = 0, optimal = 0;
  multiset<int> bestnegs, waitingnegs;
  while (hi < n + len) {
    bool pos = false;
    if (arr[lo] < 0) {
      if (waitingnegs.count(arr[lo])) {
        waitingnegs.erase(waitingnegs.find(arr[lo]));
      } else {
        bestnegs.erase(bestnegs.find(arr[lo]));
        pos = true;
      }
    }
    if (pos)
      sum += arr[lo];
    else
      sum -= arr[lo];
    if (arr[hi + 1] < 0) {
      waitingnegs.insert(arr[hi + 1]);
    }
    sum += arr[hi + 1];
    while (bestnegs.size() < k && waitingnegs.size()) {
      sum -= *waitingnegs.begin() * 2;
      bestnegs.insert(*waitingnegs.begin());
      waitingnegs.erase(waitingnegs.begin());
    }
    while (true) {
      if (waitingnegs.size() == 0 || bestnegs.size() == 0) break;
      auto it = bestnegs.end();
      int cur = *(--it), wait = *waitingnegs.begin();
      if (cur <= wait) {
        break;
      }
      bestnegs.erase(it);
      waitingnegs.erase(waitingnegs.begin());
      bestnegs.insert(wait);
      waitingnegs.insert(cur);
      sum += 2 * cur - 2 * wait;
    }
    lo++, hi++;
    if (lo >= len) optimal = max(optimal, sum);
  }
  return optimal;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> len;
  for (int i = 0; i < n; i++) {
    cin >> arr[i + len];
  }
  cin >> k;
  long long res = solve();
  for (int i = len; i < len + n; i++) arr[i] *= -1;
  res = max(res, solve());
  cout << res << endl;
  return 0;
}
