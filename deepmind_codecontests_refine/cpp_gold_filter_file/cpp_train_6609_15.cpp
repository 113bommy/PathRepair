#include <bits/stdc++.h>
using namespace std;
long long ppow[19];
long long func(long long num) {
  int dig = 0;
  int last = 0;
  long long temp = num;
  long long res = 0;
  while (temp) {
    dig++;
    if (temp <= 9) last = temp;
    temp /= 10;
  }
  for (int i = 1; i < dig; i++) {
    res += ppow[i - 1];
  }
  if (last == 1) {
    num -= ppow[dig - 1];
    res += num + 1;
  } else {
    res += ppow[dig - 1];
  }
  return res;
}
int n, k;
double prop[1001];
double DP[1002][1002];
int main() {
  ios_base::sync_with_stdio(0);
  ppow[0] = 1;
  for (int i = 1; i <= 18; i++) ppow[i] = ppow[i - 1] * 10LL;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    long long a, b;
    cin >> a >> b;
    prop[i] = func(b) - func(a - 1);
    prop[i] /= (b - a + 1);
  }
  cin >> k;
  DP[0][0] = 1;
  for (int i = 1; i <= n; i++) DP[i][k] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      DP[i][j] = (1.0 - prop[i]) * DP[i - 1][j];
      if (j != 0) DP[i][j] += prop[i] * DP[i - 1][j - 1];
    }
  }
  double ans = 0;
  for (int i = n; i * 100 >= k * n; i--) {
    ans += DP[n][i];
  }
  cout << setprecision(15);
  cout << ans;
  return 0;
}
