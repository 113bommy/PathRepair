#include <bits/stdc++.h>
using namespace std;
const int inf = (int)1e9;
const long long llinf = (long long)9e18;
const int N = (int)1e5 + 111;
long long dp[N];
int main() {
  int n, c;
  scanf("%d %d", &n, &c);
  if (c == 0) {
    printf("0");
    return 0;
  }
  vector<int> a(n);
  vector<long long> pref(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    pref[i] = (long long)a[i] + (i > 0 ? pref[i - 1] : (long long)0);
  }
  multiset<int> mn;
  for (int i = 0; i < n; i++) {
    mn.insert(a[i]);
    dp[i] = (long long)a[i] + (i > 0 ? dp[i - 1] : (long long)0);
    if (i + 1 >= c) {
      dp[i] = min(dp[i], (i - c >= 0 ? dp[i - c] : (long long)0) + pref[i] -
                             (i - c >= 0 ? pref[i - c] : (long long)0) -
                             (long long)(*mn.begin()));
      mn.erase(mn.find(a[i + 1 - c]));
    }
  }
  printf("%lld", dp[n - 1]);
  return 0;
}
