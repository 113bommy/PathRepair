#include <bits/stdc++.h>
using namespace std;
void io() {}
void solve() {
  int r, c, d;
  cin >> r >> c >> d;
  int n = r * c;
  vector<int> arr;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int x;
      cin >> x;
      arr.push_back(x);
    }
  }
  sort(arr.begin(), arr.end());
  int v = arr[0] % d;
  for (int i = 1; i < n; i++) {
    if (arr[i] % d != v) {
      cout << -1;
      return;
    }
  }
  long long median_index = ceil(n / (double)2);
  long long val = arr[median_index];
  long long moves = 0;
  for (int i = 0; i < n; i++) {
    long long diff = abs(arr[i] - val);
    moves += diff / 2;
  }
  cout << moves;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  io();
  solve();
  return 0;
}
