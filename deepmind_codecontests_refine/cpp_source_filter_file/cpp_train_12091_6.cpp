#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long res = 0;
int mx, prmx;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m >> k;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    if (a > mx) {
      prmx = mx;
      mx = a;
    } else {
      prmx = max(prmx, a);
    }
  }
  cout << 1ll * (m / k) * prmx + 1ll * (m - m / k) * mx;
  return 0;
}
