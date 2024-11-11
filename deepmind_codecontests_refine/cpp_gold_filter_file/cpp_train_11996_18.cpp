#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n, m;
int gi() {
  char a = getchar();
  int b = 0;
  while (a < '0' || a > '9') a = getchar();
  while (a >= '0' && a <= '9') b = b * 10 + a - '0', a = getchar();
  return b;
}
int s[maxn], ans[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 1; i < 5001; i++) {
    if (i % 2 == 0)
      s[i] = (i / 2) * (i / 2 - 1);
    else
      s[i] = (i / 2) * (i / 2);
  }
  if (m > s[n]) {
    cout << "-1" << endl;
    return 0;
  } else {
    int l = 0, left = 0;
    for (int i = 1, _e = n; i <= _e; ++i) {
      if (s[i] >= m) {
        l = i;
        left = m - s[l - 1];
        break;
      }
    }
    int t = l - 1 - 2 * left;
    ans[l] = (2 * l - 2 * left - 1);
    for (int i = l + 1, _e = n; i <= _e; ++i)
      ans[i] = 100000000 + (i - l) * 5002;
    for (int i = 1, _e = l - 1; i <= _e; ++i) ans[i] = i;
    for (int i = 1, _e = n; i <= _e; ++i) cout << ans[i] << ' ';
    cout << endl;
  }
  return 0;
}
