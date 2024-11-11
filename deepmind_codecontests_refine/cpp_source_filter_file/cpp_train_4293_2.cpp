#include <bits/stdc++.h>
using namespace std;
int arr[106];
int memo[106];
int solve(int n, int reff) {
  for (int i = 1; i <= n; i++) {
    if ((memo[i] == -1) && i > reff) {
      memo[i] = 1;
      return i;
    }
  }
  return 0;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    memset(memo, -1, sizeof memo);
    cin >> n;
    int cnt = 1;
    for (int i = 0; i < n; i++) {
      cin >> x;
      arr[cnt] = x;
      memo[x] = 1;
      cnt += 2;
    }
    n *= 2;
    bool chk = false;
    for (int i = 1; i <= n; i++) {
      if (!(i & 1)) {
        arr[i] = solve(n, arr[i - 1]);
      }
      if (!arr[i]) {
        chk = true;
        break;
      }
    }
    if (chk) {
      cout << -1 << endl;
      continue;
    }
    for (int i = 1; i <= n; i++) cout << arr[i] << ' ';
    cout << endl;
  }
  return 0;
}
