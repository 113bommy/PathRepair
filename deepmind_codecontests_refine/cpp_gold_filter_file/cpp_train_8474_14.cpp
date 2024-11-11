#include <bits/stdc++.h>
using namespace std;
long long k, a, i, j, n, num, ans, sum[10001];
string s;
long long p[100000];
int main() {
  cin >> a;
  cin >> s;
  for (i = 0; i < s.length(); i++) sum[i + 1] = sum[i] + s[i] - '0';
  n = s.length();
  for (i = 1; i <= n; i++)
    for (j = i; j <= n; j++) p[sum[j] - sum[i - 1]]++;
  if (a == 0) {
    cout << n * (n + 1) * p[0] - p[0] * p[0];
    return 0;
  };
  for (i = 1; i <= 40000; i++)
    if (p[i] && a % i == 0 && a / i <= 40000) ans += p[a / i] * p[i];
  cout << ans;
  return 0;
}
