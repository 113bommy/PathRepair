#include <bits/stdc++.h>
using namespace std;
ifstream fin("AAtest.in.txt");
int n, q, k, x, p, c;
vector<int> t;
void pane(int n, int x, int y, int i, int j, int v, int m) {
  if (j < x or y < i) return;
  if (i <= x and y <= j) {
    if (t[n] < v or (m and i == x)) t[n] = v;
    return;
  }
  t[n * 2] = max(t[n * 2], t[n]);
  t[n * 2 + 1] = max(t[n * 2 + 1], t[n]);
  pane(n * 2, x, (x + y) / 2, i, j, v, m);
  pane(n * 2 + 1, (x + y) / 2 + 1, y, i, j, v, m);
  t[n] = -1;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cerr.tie(0);
  cin >> n;
  c = 1;
  while (c <= n) c <<= 1;
  t.resize(2 * c + 5, -1);
  for (int(i) = (0); ((i)) < ((n)); ((i))++) cin >> t[c + i];
  cin >> q;
  while (q--) {
    cin >> k;
    int l = 1, r = n;
    if (k == 1) {
      cin >> p >> x;
      l = p, r = p;
      pane(1, 1, c, l, r, x, 1);
    } else {
      cin >> x;
      pane(1, 1, c, l, r, x, 0);
    }
  }
  for (int(i) = (0); ((i)) < ((n)); ((i))++) pane(1, 1, c, i + 1, i + 1, 0, 0);
  for (int(i) = (0); ((i)) < ((n)); ((i))++) cout << t[i + c] << " ";
}
