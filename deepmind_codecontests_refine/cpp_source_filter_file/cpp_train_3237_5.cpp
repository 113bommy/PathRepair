#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e3 + 10;
const int MOD = 1e9 + 7;
struct Point {
  long long x, y;
} p[MAX];
int cmp(const Point& A, const Point& B) { return A.x < B.x; }
Point operator-(Point A, Point B) { return (Point){A.x - B.x, A.y - B.y}; }
long long operator^(Point A, Point B) { return A.x * B.y - A.y * B.x; }
long long cal(int x, int y, int z) {
  return abs((p[y] - p[x]) ^ (p[z] - p[x]));
}
struct lenka {
  int x, y;
  double k;
};
vector<lenka> q;
int cmp1(const lenka& A, const lenka& B) { return A.k < B.k; }
int pos[MAX], id[MAX];
int main() {
  int n;
  cin >> n;
  long long S;
  cin >> S;
  S *= 2;
  for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
  sort(p + 1, p + n + 1, cmp);
  for (int i = 1; i <= n; i++) pos[i] = id[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      double k;
      if (p[i].x == p[j].x)
        k = 1e18;
      else
        k = 1.0 * (p[j].y - p[i].y) / (p[j].x - p[i].x);
      q.push_back((lenka){pos[i], pos[j], k});
    }
  }
  sort(q.begin(), q.end(), cmp1);
  for (int i = 0; i < q.size(); i++) {
    int x = pos[q[i].x], y = pos[q[i].y];
    if (x > y) swap(x, y);
    int l = 1, r = x - 1;
    while (r >= l) {
      int m = (l + r) / 2;
      if (cal(id[m], id[x], id[y]) == S) {
        puts("Yes");
        printf("%lld %lld\n", p[id[m]].x, p[id[m]].y);
        printf("%lld %lld\n", p[id[x]].x, p[id[x]].y);
        printf("%lld %lld\n", p[id[y]].x, p[id[y]].y);
        return 0;
      }
      if (cal(id[m], id[x], id[y]) > S)
        l = m + 1;
      else
        r = m - 1;
    }
    l = y + 1, r = n;
    while (r >= l) {
      int m = (l + r) / 2;
      if (cal(id[m], id[x], id[y]) == S) {
        puts("Yes");
        printf("%lld %lld\n", p[id[m]].x, p[id[m]].y);
        printf("%lld %lld\n", p[id[x]].x, p[id[x]].y);
        printf("%lld %lld\n", p[id[y]].x, p[id[y]].y);
        return 0;
      }
      if (cal(id[m], id[x], id[y]) > S)
        r = m - 1;
      else
        l = m + 1;
    }
    if (n > 1211) puts("No");
    swap(pos[q[i].x], pos[q[i].y]);
    swap(id[x], id[y]);
  }
  puts("No");
  return 0;
}
