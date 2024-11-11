#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 5;
const int infinity = 0x3f3f3f;
int n, m, k, beg, en;
int d[maxn];
bool visit[maxn];
struct node {
  int x, y;
} a[maxn];
void spfa() {
  memset(d, infinity, sizeof(d));
  queue<int> q;
  q.push(beg);
  visit[beg] = 1;
  d[beg] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    visit[u] = 0;
    for (int i = 1; i <= k; i++) {
      if (i == u) {
        continue;
      }
      int w = infinity;
      int dx = abs(a[i].x - a[u].x);
      int dy = abs(a[i].y - a[u].y);
      if (dx + dy == 1) {
        w = 0;
      } else if (dx <= 2 || dy <= 2) {
        w = 1;
      }
      if (d[i] > (d[u] + w)) {
        d[i] = d[u] + w;
        if (!visit[i]) {
          q.push(i);
          visit[i] = 1;
        }
      }
    }
  }
  if (d[en] != infinity) {
    cout << d[en] << endl;
  } else {
    cout << -1 << endl;
  }
}
int main() {
  cin >> n >> m >> k;
  bool flag = 0;
  if (n * m == k) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 1; i <= k; i++) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x == n && a[i].y == m) {
      flag = 1;
      en = i;
    }
    if (a[i].x == 1 && a[i].y == 1) {
      beg = i;
    }
  }
  if (!flag) {
    a[++k].x = (n + 1);
    a[k].y = (m + 1);
    en = k;
  }
  spfa();
  return 0;
}
