#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)1e15;
const int MAXN = 1e5 + 1;
int n, haveDays, windowSize;
long long height[MAXN], IncreasedFromWindow[MAXN];
bool ok(long long canBeMaxHeight) {
  long long increaseInSomeWindow = 0, needDays = 0;
  memset(IncreasedFromWindow, 0, sizeof(IncreasedFromWindow));
  for (int i = 0; i < n; i++) {
    if (i >= windowSize)
      increaseInSomeWindow -= IncreasedFromWindow[i - windowSize];
    if (height[i] + increaseInSomeWindow < canBeMaxHeight) {
      long long need = canBeMaxHeight - height[i] - increaseInSomeWindow;
      IncreasedFromWindow[i] = need;
      increaseInSomeWindow += need;
      needDays += need;
    }
  }
  return needDays <= haveDays;
}
long long binSearchOnHeight() {
  long long L = *min_element(height, height + n), R = INF, ans = L;
  while (L <= R) {
    long long mid = (L + R) / 2;
    if (ok(mid))
      L = mid + 1, ans = mid;
    else
      R = mid - 1;
  }
  return ans;
}
int main() {
  cin >> n >> haveDays >> windowSize;
  for (int i = 0; i < n; i++) cin >> height[i];
  cout << binSearchOnHeight() << endl;
  return 0;
}
