#include <bits/stdc++.h>
using namespace std;
long long M = 1e9 + 7;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cerr.tie(0);
  int n, m, s, f, l, r, a[100005], b[100005], t[100005];
  cin >> n >> m >> s >> f;
  for (int i = 0; i < m; i++) {
    cin >> t[i] >> a[i] >> b[i];
  }
  int dir = 1;
  if (s > f) dir = -1;
  int t2 = 1, j = 0;
  while (s != f) {
    int mv = 0;
    if (j < m && t2 == t[j]) {
      if ((a[j] <= s && b[j] >= s) || (a[j] <= (s + dir) && b[j] >= (s + dir)))
        mv = 1;
      j++;
    }
    if (mv == 0) {
      s += dir;
      if (dir == 1)
        cout << "R";
      else
        cout << "L";
    } else {
      cout << "X";
    }
    t2++;
  }
  return 0;
}
