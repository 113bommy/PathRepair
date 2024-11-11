#include <bits/stdc++.h>
using namespace std;
int n, fv[50];
long long ans;
int main() {
  cin >> n;
  for (int i = 1, x, cnt = 0; i <= n; i++, cnt = 0) {
    cin >> x;
    while (x > 1) {
      if (x & 1) cnt++;
      x >>= 1;
    }
    fv[cnt]++;
  }
  for (int i = 0; i <= 31; i++) ans += 1LL * fv[i] * (fv[i] - 1) / 2;
  cout << ans;
  return 0;
}
