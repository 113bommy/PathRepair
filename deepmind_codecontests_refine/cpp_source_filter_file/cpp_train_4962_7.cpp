#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int T = 1;
  for (int test_case = 1; test_case <= T; ++test_case) {
    int n, a, b, c, t;
    cin >> n >> a >> b >> c >> t;
    int input[n + 1];
    for (int i = 1; i <= n; ++i) cin >> input[i];
    map<int, int> count;
    for (int i = 1; i <= n; ++i) ++count[input[i]];
    int unread = 0;
    int res = 0;
    for (int time = 1; time <= t; ++time) {
      res += unread * c;
      unread += count[time];
      if (count[time] > 0) {
        res += (a - (t - time) * b) * count[t];
      }
    }
    cout << max(res, n * a) << '\n';
  }
}
