#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 4e3 + 4;
int n, r;
int x[maxn];
struct NODE {
  int x;
  double y;
} dot[maxn];
double hih[maxn];
int main() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x[i]);
    dot[i].x = x[i];
  }
  dot[1].y = r;
  for (int i = 1; i <= 4000; i++) hih[i] = -1;
  hih[(int)dot[1].x] = r;
  for (int i = 2; i <= n; i++) {
    double ans = r;
    for (int j = max(1, dot[i].x - r - r); j <= dot[i].x + r + r; j++) {
      if (hih[j] < 0) continue;
      ans = max(ans, hih[j] + sqrt((r + r) * (r + r) -
                                   (j - dot[i].x) * (j - dot[i].x)));
    }
    hih[(int)dot[i].x] = ans;
    dot[i].y = ans;
  }
  for (int i = 1; i <= n; i++) {
    printf("%.7lf ", dot[i].y);
  }
}
