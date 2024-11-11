#include <bits/stdc++.h>
using namespace std;
map<long long int, string> mp;
long long int two_pointer(long long int ar[], long long int val,
                          long long int n) {
  long long int l = 1, r = n, cnt = 0;
  while (l < r) {
    long long int res = ar[l] + ar[r];
    if (res == val)
      cnt++, l++, r--;
    else if (res > val)
      r--;
    else
      l++;
  }
  return cnt;
}
void sol() {
  long long int n;
  cin >> n;
  long long int ar[n + 1];
  for (long long int i = 1; i <= n; i++) cin >> ar[i];
  sort(ar + 1, ar + 1 + n);
  long long int mx = ar[n] + ar[n], ans = 0;
  for (long long int i = 2; i <= mx; i++) {
    long long int x = two_pointer(ar, i, n);
    ans = max(ans, x);
  }
  cout << ans << endl;
  return;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  long long int t;
  cin >> t;
  while (t--) sol();
  return 0;
}
