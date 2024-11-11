#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:64000000")
using namespace std;
const int INF = (int)1E9;
const long long INF64 = (long long)1E18;
const long double EPS = 1E-9;
const long double PI = 3.1415926535897932384626433832795;
const int MAXN = 20;
int a[MAXN], n, r[MAXN], c[MAXN], m[MAXN][MAXN], d1, d2, s;
bool used[MAXN];
void gen(int x, int y) {
  if (x == n) {
    if (d1 == s && d2 == s) {
      cout << s << endl;
      for (int i = 0; i < (int)(n); i++) {
        for (int j = 0; j < (int)(n); j++) cout << m[i][j] << " ";
        cout << endl;
      }
      exit(0);
    }
    return;
  }
  if (y == n) {
    if (r[x] == s) gen(x + 1, 0);
    return;
  }
  if (x == n - 1 && y != 0 && d2 != s) return;
  int prev = -1;
  for (int i = 0; i < (int)(n * n); i++)
    if (!used[i]) {
      if (prev == a[i]) continue;
      m[x][y] = a[i];
      used[i] = true;
      r[x] += a[i];
      c[y] += a[i];
      if (x == y) d1 += a[i];
      if (x + y == n - 1) d2 += a[i];
      if (x != n - 1 || c[y] == s) gen(x, y + 1);
      if (x == y) d1 -= a[i];
      if (x + y == n - 1) d2 -= a[i];
      r[x] -= a[i];
      c[y] -= a[i];
      used[i] = false;
      prev = a[i];
    }
}
int main() {
  cin >> n;
  for (int i = 0; i < (int)(n * n); i++) {
    cin >> a[i];
    s += a[i];
  }
  s /= n;
  sort(a, a + n * n);
  gen(0, 0);
  return 0;
}
