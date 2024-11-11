#include <bits/stdc++.h>
const int INF = 0x3f3f3f3f;
using namespace std;
void file(bool opt) {
  if (opt && fopen("in.txt", "r"))
    freopen("in.txt", "r", stdin), freopen("out.txt", "w", stdout);
}
struct node {
  double x, y;
} point[100000 + 5], tu[100000 + 5];
int tot = 0;
int n;
double multi(node p0, node p1, node p2) {
  return (p1.x - p0.x) * (p2.y - p0.y) - (p2.x - p0.x) * (p1.y - p0.y);
}
double dis(node a, node b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool cmp(node a, node b) {
  double x = multi(a, b, point[1]);
  if (x > 0 || (x == 0 && dis(a, point[1]) < dis(b, point[1]))) return 1;
  return 0;
}
void Graham() {
  int k = 1;
  for (int i = 1; i <= n; i++)
    if (point[i].y < point[k].y ||
        (point[i].y == point[k].y && point[i].x < point[k].x))
      k = i;
  swap(point[1], point[k]);
  sort(point + 2, point + 1 + n, cmp);
  tot = 2, tu[1] = point[1], tu[2] = point[2];
  for (int i = 3; i <= n; i++) {
    while (tot >= 1 && multi(tu[tot], tu[tot - 1], point[i]) >= 0) tot--;
    tu[++tot] = point[i];
  }
}
int main() {
  file(1);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lf%lf", &point[i].x, &point[i].y);
    point[i].y = point[i].y - point[i].x * point[i].x;
  }
  if (n == 1) {
    puts("0");
    return 0;
  }
  Graham();
  int ans = 0;
  for (int i = 1; i <= tot; i++) {
    node a = tu[i], b = tu[(i + 1) > tot ? 1 : (i + 1)],
         c = {0, (long long)1e8};
    if (a.x != b.x) {
      double x = multi(a, b, c);
      if (x < 0) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}
