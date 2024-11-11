#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, i, j, k, m, a;
  cin >> n >> m >> a;
  long long s = 0;
  long long t = 0;
  if (n / a == 0)
    s = n / a;
  else
    s = n / a + 1;
  if (m / a == 0)
    t = n / a;
  else
    t = n / a + 1;
  cout << 1ll * s * t << endl;
  return 0;
}
