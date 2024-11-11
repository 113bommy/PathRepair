#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const int inf = 0x3f3f3f3f;
const long long inff = 0x3f3f3f3f3f3f3f3f;
int t;
int s;
int cnt[1000010];
int cnt2[1000010];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  int mx = 0;
  int a, b;
  for (int i = 0; i < t; i++) {
    cin >> s;
    cnt[s]++;
    mx = max(mx, s);
  }
  b = mx;
  int x = 1, y = 1;
  for (int i = 1; i <= mx; i++)
    if (cnt[i] != (i << 2)) {
      x = i;
      break;
    }
  int n, m;
  for (n = 1; n <= sqrt(t); n++)
    if (t % n == 0) {
      m = t / n;
      y = m + n - x - b;
      if (abs(n - x) + abs(m - y) != b) continue;
      int flag = 1;
      for (int i = 0; i <= n + m; i++) cnt2[i] = 0;
      for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) cnt2[abs(i - x) + abs(j - y)]++;
      for (int i = 1; i <= n + m; i++) {
        if (cnt[i] != cnt2[i]) {
          flag = 0;
          break;
        }
      }
      if (flag) {
        cout << n << " " << m << endl;
        cout << x << " " << y << endl;
        return 0;
      }
    }
  cout << -1 << endl;
  return 0;
}
