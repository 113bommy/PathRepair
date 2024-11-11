#include <bits/stdc++.h>
using namespace std;
const int maxn = 6e5 + 10;
const int inf = ~0u >> 2;
long long a[maxn];
long long b[maxn];
bool isprime(int n) {
  if (n == 2) return true;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int flag = n / 2 + 1;
  for (int i = 1; i <= n; i++) cin >> a[i];
  int cnt = 0;
  for (int i = 2; i <= n; i += 2) b[++cnt] = a[i];
  for (int i = 1; i <= n; i += 2) b[++cnt] = a[i];
  for (int i = 2; i <= n; i += 2) b[++cnt] = a[i];
  long long ans = 0;
  for (int i = 1; i <= flag; i++) ans += b[i];
  long long sum = ans;
  for (int i = flag + 1; i <= flag; i++) {
    sum += a[i];
    sum -= a[i - flag];
    ans = max(ans, sum);
  }
  cout << ans << endl;
  return 0;
}
