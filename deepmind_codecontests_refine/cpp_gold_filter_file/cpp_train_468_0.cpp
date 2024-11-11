#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 500100;
string s;
int n, a, b, t;
int cost(int i) { return a + 1 + b * (s[i] == 'w'); }
int main() {
  cin >> n >> a >> b >> t >> s;
  t -= 1 + b * (s[0] == 'w');
  if (t < 0) {
    cout << 0;
    return 0;
  }
  int ans = 1;
  int p1 = 0;
  int cp = 0;
  while (p1 < n - 1 && cp + cost(p1 + 1) <= t) {
    cp += cost(p1 + 1);
    p1++;
  }
  ans = max(ans, p1 + 1);
  int cp2 = 0;
  for (int p2 = n - 1; p2 > p1; p2--) {
    cp2 += a + cost(p2);
    while (p1 > 0 && cp2 + cp > t) {
      cp -= cost(p1);
      p1--;
    }
    if (cp2 + cp > t) {
      break;
    }
    ans = max(ans, p1 + 1 + n - p2);
  }
  p1 = n;
  cp = 0;
  while (p1 > 1 && cp + cost(p1 - 1) <= t) {
    cp += cost(p1 - 1);
    p1--;
  }
  ans = max(ans, 1 + n - p1);
  cp2 = 0;
  for (int p2 = 1; p2 < p1; p2++) {
    cp2 += a + cost(p2);
    while (p1 < n && cp2 + cp > t) {
      cp -= cost(p1);
      p1++;
    }
    if (cp2 + cp > t) {
      break;
    }
    ans = max(ans, 1 + p2 + n - p1);
  }
  cout << ans << '\n';
  return 0;
}
