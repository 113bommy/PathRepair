#include <bits/stdc++.h>
using namespace std;
void fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
const int N = 100 * 100 + 5;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int dp[N], n, m, c, d;
int go(int i) {
  if (i < 0) return 0;
  if (i == 0) return 0;
  int &ret = dp[i];
  if (~ret) return ret;
  ret = min({go(i - n) + c, go(i - m) + d});
  return ret;
}
int main() {
  fast();
  memset(dp, -1, sizeof(dp));
  cin >> c >> d >> n >> m;
  int k;
  cin >> k;
  cout << go(n * m - k) << "\n";
}
