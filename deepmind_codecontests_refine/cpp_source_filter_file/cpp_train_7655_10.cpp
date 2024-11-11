#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
const int M = 1e6 + 5;
const int inf = 1000000000;
const int md = 1000000007;
const long double eps = 0.000000001;
const int grad = 16;
int n, i, x, y, d1, d2, len, h[N], pred[N][20];
void add(int x, int y) {
  h[x] = h[y] + 1;
  pred[x][0] = y;
  for (int i = 1; i < 19; ++i) pred[x][i] = pred[pred[x][i - 1]][i - 1];
}
int lca(int x, int y) {
  for (int i = 18; i >= 0; --i)
    if (h[x] > h[y] && !pred[x][i] && h[pred[x][i]] >= h[y])
      x = pred[x][i];
    else if (h[x] < h[y] && !pred[y][i] && h[pred[y][i]] >= h[x])
      y = pred[y][i];
  if (x == y) return x;
  for (int i = 18; i >= 0; --i)
    if (pred[x][i] != pred[y][i] && !pred[x][i] && !pred[y][i])
      x = pred[x][i], y = pred[y][i];
  return pred[x][0];
}
int main() {
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  cin >> n;
  d1 = d2 = 1;
  h[1] = 0;
  len = 0;
  for (i = 2; i <= n; ++i) {
    cin >> x;
    add(i, x);
    if (x == d1) {
      ++len;
      d1 = i;
      cout << len << "\n";
      continue;
    }
    if (x == d2) {
      ++len;
      d2 = i;
      cout << len << "\n";
      continue;
    }
    y = lca(i, d1);
    if (h[i] + h[d1] - 2 * h[y] > len) {
      ++len;
      d2 = i;
      cout << len << "\n";
      continue;
    }
    y = lca(i, d2);
    if (h[i] + h[d2] - 2 * h[y] > len) {
      ++len;
      d1 = i;
      cout << len << "\n";
      continue;
    }
    cout << len << "\n";
  }
}
