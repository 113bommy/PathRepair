#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000006;
long long s[maxn], sum[maxn];
long long n, x, y;
int main() {
  cin >> n >> x >> y;
  int p;
  p = x / y;
  long long temp;
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &temp);
    s[temp]++;
    sum[temp] += temp;
  }
  for (int i = 1; i <= 1000000; i++) {
    s[i] += s[i - 1];
    sum[i] += sum[i - 1];
  }
  long long ans = n * x;
  for (int i = 2; i <= 1000000; i++) {
    long long temp = 0;
    for (int j = i; j <= 1000000 && temp < ans; j += i) {
      int k = max(j - i + 1, j - p);
      temp += 1LL * ((s[j] - s[k - 1]) * j - (sum[j] - sum[k - 1])) * y;
      temp += 1LL * (s[k - 1] - s[j - i]) * x;
    }
    ans = min(ans, temp);
  }
  cout << ans << endl;
  return 0;
}
