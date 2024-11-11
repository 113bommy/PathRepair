#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int ninf = 0xc0c0c0c0;
const long long linf = 0x3f3f3f3f3f3f3f3fll;
const long long lninf = 0xc0c0c0c0c0c0c0c0ll;
int f[1000005];
vector<int> v;
int main() {
  ios::sync_with_stdio(false);
  int m, n, ans = 1, xmax = 0;
  cin >> n;
  m = n;
  for (int i = 2; i <= n; i++)
    if (!f[i]) {
      int num = 0;
      for (int j = 1; j <= n / i; j++) f[i * j] = true;
      if (n % i == 0) ans *= i;
      while (n % i == 0) {
        num++;
        n /= i;
      }
      xmax = max(xmax, num);
      if (num) v.emplace_back(num);
    }
  if (ans == m) {
    cout << ans << ' ' << 0 << endl;
    return 0;
  }
  if (unique(v.begin(), v.end()) - v.begin() == 1) {
    if (log2(xmax) != int(log2(xmax)))
      cout << ans << ' ' << ceil(log2(xmax)) + 1 << endl;
    else
      cout << ans << ' ' << ceil(log2(xmax)) << endl;
  } else
    cout << ans << ' ' << ceil(log2(xmax)) + 1 << endl;
  return 0;
}
