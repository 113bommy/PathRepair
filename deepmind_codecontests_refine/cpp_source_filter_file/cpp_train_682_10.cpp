#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const int N = 1e6 + 7, mod = 1000000007;
int n, s[6][2], x, y, c;
int main() {
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    cin >> x;
    s[x][i / n]++;
  }
  for (int i = 1; i < 6; i++) {
    x = s[i][0] + s[i][1];
    y = x - min(s[i][0], s[i][1]);
    if (x % 2)
      c = -N;
    else
      c += y >> 1;
  }
  if (c % 2) c = -N;
  cout << (c >= 0 ? c >> 1 : -1);
  return 0;
}
