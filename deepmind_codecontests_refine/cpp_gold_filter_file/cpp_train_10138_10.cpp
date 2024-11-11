#include <bits/stdc++.h>
using namespace std;
long long n;
long long arr[200010];
long long memo[200010][2];
bool calculated[200010][2];
set<long long> currently_calculating;
long long dp(long long pos, int step) {
  if (pos == -1 && step == 1) return -1;
  if (pos < 0 || pos >= n - 1) return 0;
  if (calculated[pos][step]) return memo[pos][step];
  long long xd = pos * 1000000 + step;
  currently_calculating.insert(xd);
  long long res = 0;
  if (step == 1) {
    long long xy = (pos + arr[pos]) * 1000000 + 2;
    if (currently_calculating.count(xy) <= 0)
      res = dp(pos + arr[pos], 2);
    else
      res = -1;
  } else {
    long long xy = (pos - arr[pos]) * 1000000 + 1;
    if (currently_calculating.count(xy) <= 0)
      res = dp(pos - arr[pos], 1);
    else
      res = -1;
  }
  if (res == -1)
    memo[pos][step] = -1;
  else
    memo[pos][step] = arr[pos] + res;
  currently_calculating.erase(xd);
  calculated[pos][step] = true;
  return memo[pos][step];
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) cin >> arr[i];
  for (int i = 1; i <= n - 1; i++) {
    long long res = dp(i - 1, 2);
    if (res == -1)
      cout << -1 << endl;
    else
      cout << i + res << endl;
  }
  return 0;
}
