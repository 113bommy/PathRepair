#include <bits/stdc++.h>
using namespace std;
long long int c[100100];
string a[100100];
long long int dpf[100100];
long long int dpr[100100];
string rev(string s) {
  reverse(s.begin(), s.end());
  return s;
}
int main() {
  int n;
  std::ios::sync_with_stdio(false);
  cin >> n;
  for (long int i = 0; i < n; i++) cin >> c[i];
  for (long int i = 0; i < n; i++) cin >> a[i];
  for (long int i = 0; i < n; i++) {
    dpf[i] = dpr[i] = LLONG_MAX;
  }
  dpf[0] = 0;
  dpr[0] = c[0];
  for (long int i = 1; i < n; i++) {
    if (a[i] >= a[i - 1]) dpf[i] = dpf[i - 1];
    if (a[i] >= rev(a[i - 1]) && dpr[i - 1] != LLONG_MAX)
      dpf[i] = min(dpf[i], dpr[i - 1]);
    if (rev(a[i]) >= a[i - 1] && dpf[i - 1] != LLONG_MAX)
      dpr[i] = dpf[i - 1] + c[i];
    if (rev(a[i]) >= rev(a[i - 1]) && dpr[i - 1] != LLONG_MAX)
      dpr[i] = min(dpr[i], dpr[i - 1] + c[i]);
  }
  long long int x = min(dpf[n - 1], dpr[n - 1]);
  if (x == LLONG_MAX)
    cout << -1;
  else
    cout << x << endl;
}
