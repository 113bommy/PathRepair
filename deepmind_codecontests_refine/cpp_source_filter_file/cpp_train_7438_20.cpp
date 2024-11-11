#include <bits/stdc++.h>
void fre() {
  freopen("c://test//input.in", "r", stdin);
  freopen("c://test//output.out", "w", stdout);
}
const long long mod = 1e4 + 7;
using namespace std;
struct point {
  int x, y;
  point(int x = 0, int y = 0) {
    this->x = x;
    this->y = y;
  }
  point operator-(point &b) {
    x = x - b.x;
    y = y - b.x;
  }
};
int n, r, m, ans, pos[10000], rec[10000];
vector<point> vec;
int dis(int x, int y) { return x * x + y * y; }
int cmp(point a, point b) { return dis(a.x, a.y) > dis(b.x, b.y); }
void dfs(int s, int now, int a) {
  if (now == n) {
    if (s > ans) {
      ans = s;
      for (int i = 1; i <= 9500; i++) rec[i] = pos[i];
    }
    return;
  }
  for (int i = a; i < m; i++) {
    int add = 0;
    for (int j = 0; j < now; j++) {
      add += dis(vec[pos[j]].x - vec[i].x, vec[pos[j]].y - vec[i].y);
    }
    pos[now] = i;
    dfs(add + s, now + 1, i);
  }
  return;
}
int main() {
  while (scanf("%d%d", &n, &r) != EOF) {
    vec.clear();
    for (int i = -r; i <= r; i++) {
      for (int j = -r; j <= r; j++) {
        if (i * i + j * j <= r * r) vec.push_back(point(i, j));
      }
    }
    m = min(18, (int)vec.size());
    sort(vec.begin(), vec.end(), cmp);
    ans = 0;
    dfs(0, 0, 0);
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
      printf("%d %d\n", vec[rec[i]].x, vec[rec[i]].y);
    }
  }
}
