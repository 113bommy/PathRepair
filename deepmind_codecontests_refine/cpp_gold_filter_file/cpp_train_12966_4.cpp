#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn];
set<int> sx;
int sizex = 0;
int sizey = 0;
set<int> sy;
int main() {
  scanf("%d%d", &n, &m);
  long long k = 0;
  long long nn = (long long)n * (long long)n;
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    int nx = sx.count(x);
    int ny = sy.count(y);
    if (nx == 1 && ny == 1) {
    } else if (nx == 1 && ny == 0) {
      sy.insert(y);
      k += n - sizex;
      sizey += 1;
    } else if (nx == 0 && ny == 1) {
      sx.insert(x);
      k += n - sizey;
      sizex += 1;
    } else {
      sx.insert(x);
      sy.insert(y);
      k += 2 * n - 1 - sizex - sizey;
      sizex += 1;
      sizey += 1;
    }
    printf("%I64d%c", nn - k, i == m ? 10 : 32);
  }
  return 0;
}
