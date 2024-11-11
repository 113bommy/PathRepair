#include <bits/stdc++.h>
using namespace std;
int getIndex(const vector<int> &V, int val) {
  auto iter = upper_bound(V.begin(), V.end(), val);
  if (iter != V.begin()) {
    return distance(V.begin(), prev(iter)) + 1;
  }
  return 0;
}
int main() {
  int n, k;
  cin >> n >> k;
  int timeLeft = (4 * 60) - k;
  vector<int> arr(n, 0);
  arr[0] = 5;
  for (int i = 1; i < n; i++) {
    arr[i] = arr[i - 1] + ((i + 1) * 5);
  }
  int ans = getIndex(arr, timeLeft);
  cout << ((ans > 0) ? (ans) : 0);
  return 0;
}
