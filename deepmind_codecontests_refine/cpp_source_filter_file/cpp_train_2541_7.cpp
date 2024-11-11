#include <bits/stdc++.h>
using namespace std;
int c[10010];
bool dp[11111 * 55];
int a[11111 * 55];
int main() {
  ios_base::sync_with_stdio(false);
  int n, d;
  cin >> n >> d;
  for (int _n(n), i(0); i < _n; i++) cin >> c[i];
  memset((dp), (0), sizeof(dp));
  dp[0] = true;
  for (int _n(n), i(0); i < _n; i++) {
    for (int j = 10000 * (n + 1); j >= c[i]; --j)
      if (dp[j - c[i]]) dp[j] = true;
  }
  a[0] = 1;
  for (int i = 1; i <= 10000 * (n + 1); ++i)
    if (!dp[i])
      a[i] = a[i - 1];
    else
      a[i] = i;
  int last = 0, day = 0;
  while (1) {
    int cur = a[last + d];
    if (cur == last) break;
    last = cur;
    ++day;
  }
  cout << last << " " << day << endl;
  return 0;
}
