#include <bits/stdc++.h>
using namespace std;
stringstream ss;
long long mod = 1000000007LL;
int a[64], dp[500010];
int main() {
  int n, d;
  cin >> n >> d;
  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 500000; j >= a[i]; j--)
      if (dp[j - a[i]]) dp[j] = 1;
  }
  vector<int> cand;
  for (int i = 0; i < 500000; i++)
    if (dp[i]) cand.push_back(i);
  int now = 0, last = -1, ans = 0, i = 0;
  while (now != last) {
    last = now;
    while (i < cand.size() && cand[i] - last <= d) now = cand[i++];
    ans++;
  }
  cout << now << " " << ans - 1 << endl;
  return 0;
}
