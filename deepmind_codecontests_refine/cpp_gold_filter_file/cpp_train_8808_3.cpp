#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int bit[N][N];
void add(int x, int y, int v) {
  for (int i = x; i < N; i += i & -i)
    for (int j = y; j < N; j += j & -j) bit[i][j] += v;
}
int sum(int x, int y) {
  int res = 0;
  for (int i = x; i > 0; i -= i & -i)
    for (int j = y; j > 0; j -= j & -j) res += bit[i][j];
  return res;
}
int main() {
  int n, m, q, x1, x2, y1, y2, t;
  cin >> n >> m >> q;
  while (q--) {
    cin >> t >> x1 >> y1 >> x2 >> y2;
    if (t != 3) {
      int v = x1 * m + y1;
      v = (t == 1) ? v : -v;
      add(x1, y1, v);
      add(x1, y2 + 1, -v);
      add(x2 + 1, y1, -v);
      add(x2 + 1, y2 + 1, v);
    } else {
      if (sum(x1, y1) == sum(x2, y2))
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
