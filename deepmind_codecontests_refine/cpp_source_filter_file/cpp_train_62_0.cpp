#include <bits/stdc++.h>
using namespace std;
long long gcd1(long long a, long long b) {
  if (a == 0) return b;
  return gcd1(b % a, a);
}
long long modx(long long base, long long ex) {
  long long ans = 1LL, val = base;
  while (ex > 0LL) {
    if (ex & 1LL) ans = (ans * val) % 1000000007LL;
    val = (val * val) % 1000000007LL;
    ex = ex >> 1LL;
  }
  return ans;
}
long long a[300005], sum[300005], maxx[300005];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long d;
  int ans = 0;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum[i] = sum[i - 1] + a[i];
    if (sum[i] > d) ans = -1;
  }
  if (ans == -1) {
    cout << ans << endl;
    return 0;
  }
  maxx[n] = sum[n];
  for (int i = n - 1; i >= 1; i--) maxx[i] = max(sum[i], maxx[i + 1]);
  long long temp = 0;
  for (int i = 1; i <= n; i++) {
    if (!a[i] && sum[i] + temp < 0) {
      ans++;
      long long dep = d - (maxx[i] + temp);
      if (sum[i] + temp + dep < 0) {
        cout << "-1" << endl;
        return 0;
      }
      temp = dep;
    }
  }
  cout << ans << endl;
  return 0;
}
