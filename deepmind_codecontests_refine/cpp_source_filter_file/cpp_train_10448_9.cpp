#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6, mod = 1073741824;
int ans, a, b, c, d[maxn];
int main() {
  cin >> a >> b >> c;
  for (int i = 1; i < maxn + 10; i++) {
    for (int j = i; j < maxn + 10; j += i) {
      d[j]++;
      d[j] %= mod;
    }
  }
  for (int i = 1; i <= a; i++) {
    for (int j = 1; j <= b; j++) {
      for (int l = 1; l <= c; l++) {
        ans += d[i * j * l];
        ans %= mod;
      }
    }
  }
  cout << ans;
}
