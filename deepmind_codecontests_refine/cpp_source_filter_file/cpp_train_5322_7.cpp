#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 13;
int s[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout << setprecision(32);
  int n, m, h;
  cin >> n >> m >> h;
  for (int i = 1; i <= m; i++) {
    cin >> s[i];
  }
  if (s[h] <= 1) {
    cout << -1 << '\n';
    exit(0);
  }
  s[h]--;
  n--;
  int tot = accumulate(s + 1, s + m + 1, 0);
  if (tot < n) {
    cout << -1 << '\n';
    exit(0);
  }
  if (n > tot - s[h]) {
    cout << 1.0 << '\n';
    exit(0);
  }
  long double prod = 1.0;
  for (int i = 0; i < s[h]; i++) {
    prod *= (tot - n - i);
    prod /= (tot - i);
  }
  long double ans = 1.0 - prod;
  cout << ans << '\n';
  return 0;
}
