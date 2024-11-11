#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000009;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int MAXN = 2001;
const int MAXM = 0;
int a[18], aa[18], n, i, j, k, s;
int b[5][5];
int d1, d2, r[10];
int c[30];
bool check() {
  int s = 0, i, j;
  for (i = 0; i < n; i++) s += b[0][i];
  int s1 = 0, s2 = 0, d1 = 0, d2 = 0;
  for (i = 0; i < n; i++) {
    s1 = s2 = 0;
    for (j = 0; j < n; j++) {
      s1 += b[i][j];
      s2 += b[j][i];
    }
    if (s1 != s || s2 != s) return false;
    d1 += b[i][i];
    d2 += b[i][n - i - 1];
  }
  if (d1 != s || d2 != s) return false;
  return true;
}
void print() {
  int i, j, s = 0;
  for (i = 0; i < n; i++) s += b[0][i];
  cout << s << endl;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) cout << b[i][j] << " ";
    cout << endl;
  }
}
void rec(int x, int y) {
  if (x == n) {
    if (check()) {
      print();
      exit(0);
    }
    return;
  }
  int i, s = 0;
  if (x != 0)
    for (i = 0; i < n; i++) s += b[0][i];
  for (i = 0; i < k; i++) {
    if (c[i] == 0) continue;
    if (y == n - 1 && x != 0)
      if (r[x] + a[i] != s) continue;
    r[x] += a[i];
    b[x][y] = a[i];
    c[i]--;
    rec(x + (y == n - 1), (y == n - 1 ? 0 : y + 1));
    c[i]++;
    r[x] -= a[i];
  }
}
int main() {
  cin >> n;
  for (i = 0; i < n * n; i++) cin >> aa[i];
  k = 0;
  for (i = 0; i < n * n; i++) {
    for (j = 0; j < k; j++)
      if (aa[i] == a[j]) break;
    if (j == k) {
      c[k] = 1;
      a[k++] = aa[i];
    } else
      c[j]++;
  }
  rec(0, 0);
  return 0;
}
