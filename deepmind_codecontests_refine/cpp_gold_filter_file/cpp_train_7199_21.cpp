#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 1e9 + 7;
const unsigned long long base = 13331;
const double Pi = acos(-1.0);
const long long C = 299792458;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int a[N];
int h[N];
int main() {
  ios::sync_with_stdio(false);
  int n;
  int cnt = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (x == 0)
      cnt++;
    else
      h[x] = 1;
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int flag = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == i) continue;
    flag = 1;
    break;
  }
  if (flag == 0) {
    cout << 0 << endl;
    return 0;
  }
  int p = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) p = i;
  }
  int time = 0;
  for (int i = p + 1; i <= n; i++) {
    if (a[i] == 0) continue;
    if (i - p + 1 > a[i]) {
      time = max(time, i - p + 1 - a[i]);
    }
  }
  int ans = 0;
  int minn;
  int now = 1;
  int ans1 = n + time + p;
  for (int i = n - 1; i >= 1; i--) {
    if (a[i + 1] == 1) {
      minn = a[n] + 1;
      ans = 0;
      while (h[minn]) {
        ans++;
        minn++;
        h[a[now]] = 1;
        now++;
        if (minn > n) {
          cout << min(ans, ans1) << endl;
          return 0;
        }
      }
    }
    if (a[i + 1] - a[i] == 1) continue;
    break;
  }
  cout << ans1 << endl;
}
