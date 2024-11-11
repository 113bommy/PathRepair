#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 101;
struct node {
  int x, y;
  bool operator<(const node &a) const { return x == a.x ? x < a.x : y < a.y; }
} a[N];
struct que {
  int x, y, opt;
} b[N];
int c[N], cnt;
signed main() {
  int n;
  scanf("%d", &n);
  int cnt = 0, maxx = 0, maxy = 0;
  for (int i = 1; i <= n; i++) {
    char opt;
    scanf("%c", &opt);
    int x, y;
    scanf("%d%d", &x, &y);
    if (opt == '+') {
      if (x > y) swap(x, y);
      maxx = max(maxx, x);
      maxy = max(maxy, y);
    } else {
      if ((maxx <= x && maxy <= y) || (maxx <= y && maxy <= x))
        puts("YES");
      else
        puts("NO");
    }
  }
}
