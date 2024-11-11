#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> arr(n), lefts(n), rights(n);
  for (int &x : arr) cin >> x;
  stack<int> positions;
  for (int i = 0; i < n; ++i) {
    while (!positions.empty() && arr[positions.top()] <= arr[i])
      positions.pop();
    if (positions.empty()) {
      lefts[i] = -1;
    } else {
      lefts[i] = positions.top();
    }
    positions.push(i);
  }
  while (!positions.empty()) positions.pop();
  for (int i = n - 1; i >= 0; --i) {
    while (!positions.empty() && arr[positions.top()] <= arr[i])
      positions.pop();
    if (positions.empty()) {
      rights[i] = n;
    } else {
      rights[i] = positions.top();
    }
    positions.push(i);
  }
  while (!positions.empty()) positions.pop();
  vector<int> inv(n);
  for (int i = 0; i < n; ++i) {
    inv[arr[i]] = i;
  }
  long long res = 0;
  for (int i = 0; i < n; ++i) {
    int distL = i - lefts[i];
    int distR = rights[i] - i;
    if (distL < distR) {
      for (int j = lefts[i] + 1; j <= i; ++j) {
        if (arr[j] > arr[i]) continue;
        int Right = arr[i] - arr[j];
        int pos = inv[Right];
        if (pos > i && pos < rights[i]) {
          ++res;
        }
      }
    } else {
      for (int j = i; j < rights[i]; ++j) {
        if (arr[j] > arr[i]) continue;
        int Left = arr[i] - arr[j];
        int pos = inv[Left];
        if (pos < i && pos > lefts[i]) {
          ++res;
        }
      }
    }
  }
  cout << res / 2 << endl;
  return 0;
}
