#include <bits/stdc++.h>
using namespace std;
const int N = 1010, MAXN = 1000000;
int r[N][N], c[N][N];
int a[MAXN];
int ps[MAXN];
int main() {
  int x = 0, n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++) {
    int y;
    cin >> y;
    a[y]++;
    if (a[y] == 2)
      x--;
    else
      x++;
    ps[0] = max(ps[0], x);
  }
  cout << ps[0];
  return 0;
}
