#include <bits/stdc++.h>
using namespace std;
long long k2, k3, k5, k6, ans;
double xx;
int main() {
  cin >> k2 >> k3 >> k5 >> k6;
  ans += min(k2, min(k5, k6)) * 256;
  k2 -= min(k2, (k5, k6));
  ans += min(k3, k2) * 32;
  cout << ans;
}
