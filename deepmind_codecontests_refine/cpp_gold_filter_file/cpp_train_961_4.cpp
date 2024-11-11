#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  stack<int> track;
  vector<long long> res(n);
  int cur = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < cur) {
      cout << -1;
      return 0;
    }
    track.push(i);
    while (!track.empty() && cur < a[i]) {
      res[track.top()] = cur;
      track.pop();
      cur++;
    }
    if (cur != a[i]) {
      cout << -1;
      return 0;
    }
  }
  long long cac = 1000000;
  while (!track.empty()) {
    res[track.top()] = cac;
    track.pop();
  }
  for (int i : res) {
    cout << i << " ";
  }
}
