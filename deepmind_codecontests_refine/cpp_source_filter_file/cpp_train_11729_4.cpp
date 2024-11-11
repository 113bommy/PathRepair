#include <bits/stdc++.h>
using namespace std;
int n, x, y, z;
inline int get(string s, int k) {
  int ans = 0, len = s.length();
  int vis['z' - 'A' + 1] = {0};
  for (int i = 0; i < len; ++i) {
    vis[s[i] - 'A']++;
  }
  for (int i = 0; i < 'z' - 'A'; i++) {
    ans = max(ans, vis[i]);
  }
  int r = len - ans;
  if (k <= r) {
    return ans + k;
  } else {
    if (ans == len && n == 1) return len - 1;
    return len;
  }
}
int main() {
  string a, b, c;
  cin >> n;
  cin >> a >> b >> c;
  x = get(a, n);
  y = get(b, n);
  z = get(c, n);
  if (x > y && x > z) {
    cout << "Kuro" << endl;
  } else if (y > z && y > x)
    cout << "Shiro" << endl;
  else if (z > x && z > y)
    cout << "Katie\n";
  else
    cout << "Draw" << endl;
  return 0;
}
