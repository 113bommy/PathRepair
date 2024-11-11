#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, p;
  long long f1, f2, ans = 0, xa, xb, ya, yb, x3, x4, y3, y4, x1, x2, y1, y2, n,
                    k, l, min, max, z = 0;
  long long b[50], a[50];
  for (int i = 0; i < 50; i++) {
    a[i] = 0;
    b[i] = 0;
  }
  cin >> s;
  cin >> p;
  n = p.length();
  k = s.length();
  if (k < n) {
    cout << 0;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    b[p[i] - 'a' + 1]++;
  }
  for (int i = 0; i < n; i++) {
    if (s[i] == '?') {
      a[0]++;
    } else
      a[s[i] - 'a' + 1]++;
  }
  f1 = 1;
  for (int j = 1; j < 'z' - 'a' + 1; j++) {
    if (a[j] > b[j]) {
      f1 = 0;
      break;
    }
  }
  ans = f1;
  for (int i = 1; i < k - n + 1; i++) {
    f1 = 1;
    if (s[i - 1] == '?') {
      a[0]--;
    } else
      a[s[i - 1] - 'a' + 1]--;
    if (s[i + n - 1] == '?') {
      a[0]++;
    } else
      a[s[i + n - 1] - 'a' + 1]++;
    for (int j = 1; j < 'z' - 'a' + 1; j++) {
      if (a[j] > b[j]) {
        f1 = 0;
        break;
      }
    }
    ans += f1;
  }
  cout << ans;
  return 0;
}
