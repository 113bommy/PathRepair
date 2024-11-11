#include <bits/stdc++.h>
using namespace std;
int e = 0;
int count(int s) {
  e = 0;
  while (s > 0) {
    s = s / 10;
    e++;
  }
  if (e == 0) e = 1;
  return e;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t = 1;
  while (t--) {
    int n;
    string k;
    long long int x = 0, ans = 0, val = 0, g;
    cin >> n;
    cin >> k;
    int z = n;
    int c = 0;
    int y = 0;
    while (z > 0) {
      z = z / 10;
      c++;
    }
    int b, d = 0;
    long long int cnt = 0;
    int a = k.length();
    for (int i = a - 1; i >= 0;) {
      b = i;
      y = 0;
      d = 0;
      val = 0;
      for (int j = b; j >= max(b - c + 1, 0); j--) {
        g = pow(10, y);
        val = val + (g * (int(k[j]) - '0'));
        y++;
        if (val >= n) {
          val = val - ((int(k[j]) - '0') * g);
        }
      }
      i = i - count(val);
      long long int t = pow(n, x);
      ans = ans + (val * t);
      x++;
    }
    cout << ans;
  }
  return 0;
}
