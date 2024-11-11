#include <bits/stdc++.h>
int INF = 10000000;
using namespace std;
int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int ans = 0;
  bool t = false;
  if (a + b < c) {
    ans += c - (a + b);
    b += ans;
    if (!t) {
      ans++;
      b++;
      t = 1;
    }
  }
  if (a + c < b) {
    ans += b - (a + c);
    a += b - (a + c);
    if (!t) {
      ans++;
      a++;
      t = 1;
    }
  }
  if (b + c < a) {
    ans += a - (b + c);
    c += a - (b + c);
    if (!t) {
      ans++;
      c++;
      t = 1;
    }
  }
  cout << ans << endl;
  return 0;
}
