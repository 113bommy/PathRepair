#include <bits/stdc++.h>
using namespace std;
int dem[10];
int a, b, c, d, t;
int n, temp;
int ans = 0;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &temp);
    dem[temp]++;
  }
  a = dem[1];
  b = dem[2];
  c = dem[3];
  d = dem[4];
  t = min(a, b);
  a -= t;
  b -= t;
  c += t;
  ans += t;
  t = a / 3;
  c += t;
  a %= 3;
  ans += t;
  t = b / 3;
  c += 2 * t;
  b %= 3;
  ans += t;
  if (b == 2) {
    a = 1;
    b = 0;
    c++;
    ans++;
  }
  if (a == 1) {
    if (c >= 1) {
      ans += 1;
    } else if (d >= 2) {
      ans += 2;
    } else {
      ans = -1;
    }
  }
  if (a == 2) {
    if (d >= 1) {
      ans += 2;
    } else if (c >= 2) {
      ans += 2;
    } else {
      ans = -1;
    }
  }
  if (b == 1) {
    if (d >= 1) {
      ans += 1;
    } else if (c >= 2) {
      ans += 2;
    } else {
      ans = -1;
    }
  }
  cout << ans;
}
