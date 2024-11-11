#include <bits/stdc++.h>
using namespace std;
int make(int c) {
  if (c == 10000000) return 1;
  return 0;
}
long long bb[3][300005], cc[3][300005], dd[3][300005], ee[3][300005];
long long int a[3][300005 + 1];
int main() {
  int n, fl = 0, m, q;
  cin >> n;
  int i;
  for (i = 1; i <= n; i++) {
    cin >> a[1][i];
  }
  for (i = 1; i <= n; i++) {
    cin >> a[2][i];
  }
  long long ans = 0;
  int j = 0;
  for (i = 1; i <= n; i++) {
    ans += a[1][i] * j;
    j++;
  }
  for (i = n; i >= 1; i--) {
    ans += a[2][i] * j;
    j++;
  }
  long long ans1 = 0, s = 0;
  ans1 = max(ans, ans1);
  for (i = 1; i <= n; i++) {
    s += a[1][i];
    bb[1][i] = s;
  }
  for (i = n; i >= 1; i--) {
    s += a[2][i];
    bb[2][i] = s;
  }
  s = 0;
  for (i = 1; i <= n; i++) {
    s += a[2][i];
    cc[2][i] = s;
  }
  for (i = n; i >= 1; i--) {
    s += a[1][i];
    cc[1][i] = s;
  }
  j = 1;
  s = 0;
  for (i = 1; i <= n; i++) {
    s += a[1][i] * j;
    dd[1][i] = s;
    j++;
  }
  for (i = n; i >= 1; i--) {
    s += a[2][i] * j;
    dd[2][i] = s;
    j++;
  }
  j = 1;
  s = 0;
  for (i = 1; i <= n; i++) {
    s += a[2][i] * j;
    ee[2][i] = s;
    j++;
  }
  for (i = n; i >= 1; i--) {
    s += a[1][i] * j;
    ee[1][i] = s;
    j++;
  }
  j = 1;
  long long anss = 0;
  long long g;
  int curidx = 1, prev = 1, cur = 2;
  ans1 = max(ans1, ans);
  while (1) {
    g = 0;
    if (prev == 1 && cur == 2) {
      anss += j * a[cur][curidx];
      cur = 2;
      prev = 2;
      g = anss;
      if (curidx < n)
        g += ee[1][curidx + 1] +
             (j - curidx) * (cc[1][curidx + 1] - cc[2][curidx]) - ee[2][curidx];
      j++;
      curidx++;
    } else if (prev == 2 && cur == 2) {
      anss += j * a[cur][curidx];
      cur = 1;
      prev = 2;
      g = anss;
      g += ee[1][curidx] + (j - curidx) * (cc[1][curidx] - cc[2][curidx]) -
           ee[2][curidx];
      j++;
    } else if (prev == 2 && cur == 1) {
      anss += j * a[cur][curidx];
      cur = 1;
      prev = 1;
      g = anss;
      if (curidx < n)
        g += dd[2][curidx + 1] +
             (j - curidx) * (bb[2][curidx + 1] - bb[1][curidx]) - dd[1][curidx];
      j++;
      curidx++;
    } else if (prev == 1 && cur == 1) {
      anss += j * a[cur][curidx];
      cur = 2;
      prev = 1;
      g = anss;
      g += dd[2][curidx] + (j - curidx) * (bb[2][curidx] - bb[1][curidx]) -
           dd[1][curidx];
      j++;
    }
    ans1 = max(ans1, g);
    if (curidx > n) break;
  }
  cout << ans1 << endl;
}
