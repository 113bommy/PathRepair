#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {
  long long x, y;
  Point(){};
  Point(long long a, long long b) : x(a), y(b){};
  friend Point operator-(const Point &a, const Point &b) {
    return Point(a.x - b.x, a.y - b.y);
  }
} p[200007];
inline long long cross(const Point &a, const Point &b) {
  return a.x * b.y - a.y * b.x;
}
bool vis[200007];
char q[200007];
vector<int> ans;
bool go(int id) {
  vis[id] = 1;
  int las = id;
  ans.push_back(id);
  for (int i = 2; i <= n; i++) {
    id = 0;
    for (int j = 1; j <= n; j++) {
      if (vis[j]) continue;
      if (!id) {
        id = j;
        continue;
      }
      long long t = cross(p[id] - p[las], p[j] - p[las]);
      if (q[i] == 'L' && t < 0) id = j;
      if (q[i] == 'R' && t > 0) id = j;
    }
    ans.push_back(id);
    las = id;
    vis[id] = 1;
  }
  return true;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &p[i].x, &p[i].y);
  }
  scanf("%s", q + 2);
  int id = 1;
  for (int i = 2; i <= n; i++) {
    if (p[i].x < p[id].x || p[i].x == p[id].x && p[i].y < p[id].y) {
      id = i;
    }
  }
  if (go(id)) {
    for (auto y : ans) {
      printf("%d ", y);
    }
    return 0;
  }
  puts("-1");
  return 0;
}
