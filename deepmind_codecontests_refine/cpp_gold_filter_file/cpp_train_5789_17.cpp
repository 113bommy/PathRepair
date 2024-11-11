#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 29;
int l[4], s[4], r[4], p[4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 4; i++) cin >> l[i] >> s[i] >> r[i] >> p[i];
  for (int i = 0; i < 4; i++) {
    if (p[i]) {
      if (l[(i + 1) % 4] || r[(i + 3) % 4] || s[(i + 2) % 4]) {
        cout << "YES\n";
        return 0;
      }
      if (l[i] || r[i] || s[i]) {
        cout << "YES\n";
        return 0;
      }
    }
  }
  cout << "NO\n";
  return 0;
}
