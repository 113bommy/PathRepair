#include <bits/stdc++.h>
using namespace std;
const int DN = 2005;
int k, S, t, n;
int a[DN];
int main() {
  cin >> k;
  for (int i = 1; i < 2000; i++) {
    n = i + 1;
    S = k + n - 1;
    if (S + 1 > 1LL * i * 1e6) continue;
    break;
  }
  a[1] = -1;
  S++;
  for (int i = 2; i <= n; i++) {
    t = min(S, (int)1e6);
    a[i] = t;
    S -= t;
  }
  cout << n << '\n';
  for (int i = 1; i <= n; i++) cout << a[i] << ' ';
}
