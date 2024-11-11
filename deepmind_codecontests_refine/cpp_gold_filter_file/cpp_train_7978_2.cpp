#include <bits/stdc++.h>
using namespace std;
int N;
string s;
int main() {
  cin >> N >> s;
  int ans = 0;
  int c = 0, x = 0, y = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'U')
      y++;
    else
      x++;
    if (c * (x - y) < 0) ans++;
    if (x - y < 0)
      c = -1;
    else if (x - y > 0)
      c = 1;
  }
  cout << ans << endl;
  return 0;
}
