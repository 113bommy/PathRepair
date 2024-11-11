#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 2e5 + 5;
long long minPos[MAX_N], maxPos[MAX_N], low[MAX_N], high[MAX_N], ans[MAX_N];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  long long n;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> minPos[i] >> maxPos[i];
    maxPos[i] += minPos[i];
  }
  low[0] = minPos[0];
  high[0] = maxPos[0];
  for (long long i = 1; i < n; i++) {
    long long newLow = max(low[i - 1] - 1, 0ll);
    long long newHigh = high[i - 1] + 1;
    newLow = max(newLow, minPos[i]);
    newHigh = min(newHigh, maxPos[i]);
    low[i] = newLow;
    high[i] = newHigh;
  }
  long long total = 0;
  ans[n - 1] = high[n - 1];
  for (long long i = n - 2; i >= 0; i--) {
    ans[i] = min(ans[i + 1] + 1, high[i]);
  }
  for (long long i = 0; i < n; i++) {
    if (i != 0) {
      if (abs(ans[i] - ans[i - 1]) > 1 || ans[i] < minPos[i]) {
        cout << -1 << '\n';
        return 0;
      }
    }
    total += ans[i] - minPos[i];
  }
  cout << total << '\n';
  for (long long i = 0; i < n; i++) {
    cout << ans[i] << " ";
  }
  return 0;
}
