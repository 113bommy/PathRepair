#include <bits/stdc++.h>
using namespace std;
long long x, y, c;
int n;
const int maxn = 300009;
char str[maxn];
long long cnt = 0;
int main() {
  cin >> n >> x >> y;
  cin >> str;
  int now = 0;
  for (int i = 0; i < n; ++i) {
    if (str[i] == '1') {
      if (now != 0) cnt++;
      now = 0;
    } else {
      now++;
    }
  }
  if (now) cnt++;
  if (!now) return 0 * puts("0");
  if (y <= x)
    cout << cnt * y << endl;
  else {
    cout << (cnt - 1) * x + y << endl;
  }
  return 0;
}
