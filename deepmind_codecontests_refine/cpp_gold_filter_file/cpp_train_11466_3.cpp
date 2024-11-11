#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 10;
map<int, int> a, b;
int yy;
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string s;
    cin >> s;
    int mi = 0;
    int xx = 0;
    int len = s.size();
    for (int j = 0; j < len; j++) {
      if (s[j] == '(')
        xx++;
      else
        xx--;
      mi = min(mi, xx);
    }
    if (mi == 0 && xx == 0)
      yy++;
    else if (mi == 0)
      a[xx]++;
    else if (xx < 0 && mi == xx)
      b[-xx]++;
  }
  int ans = yy / 2;
  for (int i = 0; i < maxn; i++) {
    ans += min(a[i], b[i]);
  }
  cout << ans << endl;
}
