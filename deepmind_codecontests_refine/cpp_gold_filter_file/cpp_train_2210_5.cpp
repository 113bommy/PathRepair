#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, i, j, k, a[100001], p[11] = {0}, m[11] = {0};
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] < 0)
      m[-a[i]]++;
    else
      p[a[i]]++;
  }
  long long ans = 0;
  if (p[0]) {
    ans += p[0] * (p[0] - 1) / 2;
  }
  for (i = 1; i < 11; i++) {
    if (p[i] && m[i]) {
      ans += p[i] * m[i];
    }
  }
  cout << ans << endl;
}
