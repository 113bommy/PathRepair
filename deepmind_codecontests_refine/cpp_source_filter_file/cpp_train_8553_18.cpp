#include <bits/stdc++.h>
using namespace std;
const int N = 200005;
int n;
inline int lowbit(int x) { return x & -x; }
int c[N];
bool vis[N];
void add(int pos) {
  if (vis[pos]) return;
  vis[pos] = 1;
  while (pos <= n) {
    c[pos]++;
    pos += lowbit(pos);
  }
}
int sum(int pos) {
  int ret = 0;
  while (pos) {
    ret += c[pos];
    pos -= lowbit(pos);
  }
  return ret;
}
struct Point {
  int x, y;
};
Point a[N];
int main() {
  scanf("%d", &n);
  vector<int> x, y;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    x.push_back(a[i].x);
    y.push_back(a[i].y);
  }
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  x.erase(unique(x.begin(), x.end()), x.end());
  y.erase(unique(y.begin(), y.end()), y.end());
  for (int i = 1; i <= n; i++) {
    a[i].x = lower_bound(x.begin(), x.end(), a[i].x) - x.begin() + 1;
    a[i].y = lower_bound(y.begin(), y.end(), a[i].y) - y.begin() + 1;
  }
  sort(a + 1, a + n + 1,
       [](Point a, Point b) { return a.y > b.y || (a.y == b.y && a.x < b.x); });
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    add(a[i].x);
    int tmp = sum(a[i].x);
    ans += tmp * (sum(a[i + 1].y == a[i].y ? a[i + 1].x - 1 : n) - tmp + 1);
  }
  cout << ans << endl;
  return 0;
}
