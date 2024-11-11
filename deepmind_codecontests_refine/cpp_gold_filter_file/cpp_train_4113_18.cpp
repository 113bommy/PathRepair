#include <bits/stdc++.h>
using namespace std;
struct team {
  int i, j, s;
  bool operator<(const team& p) const { return s < p.s; }
};
priority_queue<team> q;
int vis[801], p[801];
int main() {
  int n, s;
  scanf("%d", &n);
  int m = 2 * n;
  for (int i = 2; i <= (m); i++) {
    for (int j = 1; j < i; j++) {
      scanf("%d", &s);
      team a;
      a.i = i;
      a.j = j;
      a.s = s;
      q.push(a);
    }
  }
  int cnt = 0;
  while (q.size() > 0) {
    team a = q.top();
    q.pop();
    if (vis[a.i] == 0 && vis[a.j] == 0) {
      vis[a.i] = 1;
      vis[a.j] = 1;
      p[a.i] = a.j;
      p[a.j] = a.i;
      cnt++;
    }
    if (cnt == n) break;
  }
  for (int i = 1; i <= m; i++) {
    printf("%d", p[i]);
    if (i < m) printf(" ");
  }
  return 0;
}
