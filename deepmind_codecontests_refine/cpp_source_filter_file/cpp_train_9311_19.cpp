#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
long long power(long long a, long long b) {
  if (b == 0) return 1;
  long long res = power(a, b / 2);
  long long ans = res * res;
  ans %= mod;
  if (b % 2 == 0) return ans;
  return (a * ans) % mod;
}
bool sortbysec(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.second < b.second);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  ;
  if (n == 1) {
    cout << 1 << "\n";
    return 0;
  }
  vector<int> pref(n), suff(n);
  suff[n - 1] = n - 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      pref[i] = pref[i - 1];
    else
      pref[i] = i;
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i + 1] > a[i])
      suff[i] = suff[i + 1];
    else
      suff[i] = i;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i && i != n - 1 && a[i + 1] > a[i - 1])
      ans = max(ans, suff[i + 1] - pref[i - 1] + 1);
    if (i != n - 1) ans = max(ans, suff[i + 1] - i + 1);
    if (i) ans = max(ans, i - pref[i - 1] + 1);
  }
  cout << ans << "\n";
  return 0;
}
