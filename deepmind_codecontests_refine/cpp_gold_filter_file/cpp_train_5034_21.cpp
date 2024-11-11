#include <bits/stdc++.h>
using namespace std;
const int inf = 1000 * 1000 * 1000;
const double eps = 1e-9;
int n;
int a[1 << 17], u1[1 << 17], u2[1 << 17], pref[1 << 17];
int main() {
  memset(u1, 0, sizeof(u1));
  memset(u2, 0, sizeof(u2));
  int t = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    t += a[i];
  }
  if (t % 3)
    cout << "0" << endl;
  else {
    int p = t / 3;
    pref[0] = a[0];
    for (int i = 1; i < n; ++i) pref[i] = pref[i - 1] + a[i];
    for (int i = 0; i < n; ++i) u1[i] = pref[i] == p;
    for (int i = 0; i < n; ++i) u2[i] = pref[i] == 2 * p;
    u2[n - 1] = 0;
    u2[0] = 0;
    for (int i = n - 2; i >= 0; --i) u2[i] += u2[i + 1];
    long long res = 0;
    for (int i = 0; i < n - 1; ++i)
      if (u1[i]) res += u2[i + 1];
    cout << res << endl;
  }
  return 0;
}
