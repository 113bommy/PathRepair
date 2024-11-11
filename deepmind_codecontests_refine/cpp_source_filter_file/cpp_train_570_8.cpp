#include <bits/stdc++.h>
using namespace std;
long long modx(long long Base, long long exponent) {
  long long ans = 1;
  if (Base == 1) return Base;
  while (exponent) {
    if (exponent & 1) ans = (ans * Base) % 1000000007;
    Base = (Base * Base) % 1000000007;
    exponent = exponent >> 1;
  }
  return ans;
}
long long inmodx(long long num) { return (modx(num, 1000000005LL)); }
bool cmp() { return false; }
int a[1000009], b[1000009];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, s, j, ans = 0;
  cin >> n;
  for (i = (1); i < (n + 1); i++) cin >> a[i];
  a[0] = a[1];
  b[1] = a[1];
  b[n] = a[n];
  a[n + 1] = a[n];
  s = 1;
  for (i = (1); i < (n + 2); i++) {
    if (a[i] == a[i - 1]) {
      ans = max(ans, (i - s - 1) / 2);
      if (a[s] == a[i]) {
        for (j = (s + 1); j < (i); j++) b[j] = a[s];
      } else {
        for (i = (s + 1); i < (s + 1 + (i - s - 2) / 2); i++) b[j] = a[s];
        for (j = (s + 1 + (i - s - 2) / 2); j < (i); j++) b[j] = a[i];
      }
      b[i] = a[i];
      s = i;
    }
  }
  cout << ans << '\n';
  for (i = (1); i < (n + 1); i++) cout << b[i] << " ";
  return 0;
}
