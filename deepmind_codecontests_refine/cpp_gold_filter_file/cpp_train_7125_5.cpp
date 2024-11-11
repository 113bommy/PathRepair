#include <bits/stdc++.h>
using namespace std;
const long long int mx = 1e5 + 10;
long long int a[mx], s[mx], e[mx];
int main() {
  long long int n;
  cin >> n;
  for (long long int i = 1; i <= n; i++) cin >> a[i];
  long long int res = LLONG_MIN;
  for (long long int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i])
      s[i] = s[i - 1] + 1;
    else
      s[i] = 1;
    res = max(res, s[i]);
  }
  if (res < n) res++;
  for (long long int i = n; i >= 1; i--) {
    if (a[i + 1] > a[i])
      e[i] = e[i + 1] + 1;
    else
      e[i] = 1;
    if (a[i + 1] - a[i - 1] > 1) res = max(res, s[i - 1] + e[i + 1] + 1);
  }
  cout << res << endl;
  return 0;
}
