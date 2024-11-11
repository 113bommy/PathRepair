#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int usea[MAXN], useb[MAXN];
struct node {
  int x, y;
  friend bool operator<(node a, node b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  }
  void rd() { scanf("%d%d", &y, &x); }
} a[MAXN], b[MAXN];
int main() {
  int n, m;
  while (cin >> n >> m) {
    for (int i = 0; i < n; i++) a[i].rd();
    for (int i = 0; i < m; i++) b[i].rd();
    sort(a, a + n);
    sort(b, b + m);
    memset(usea, 0, sizeof(usea));
    memset(useb, 0, sizeof(useb));
    int x = 0, y = 0;
    int l = 0, r = 0;
    while (l < n && r < m) {
      if (a[l].x == b[r].x) {
        if (a[l].y == b[r].y) {
          y++;
          l++;
          r++;
        } else if (a[l].y < b[r].y) {
          usea[a[l].x]++;
          l++;
        } else {
          useb[b[r].x]++;
          r++;
        }
      } else if (a[l].x < a[r].x) {
        usea[a[l].x]++;
        l++;
      } else {
        useb[b[r].x]++;
        r++;
      }
    }
    while (l < n) usea[a[l++].x]++;
    while (r < m) useb[b[r++].x]++;
    x = y;
    for (int i = 0; i < 1001; i++) x += min(usea[i], useb[i]);
    cout << x << " " << y << endl;
  }
  return 0;
}
