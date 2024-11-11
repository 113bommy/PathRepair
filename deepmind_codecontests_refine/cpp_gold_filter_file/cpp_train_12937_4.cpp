#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], pos[maxn];
int t[maxn];
int n;
priority_queue<pair<int, int> > q;
int b[maxn][3];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pos[i] = a[i];
  sort(pos + 1, pos + n + 1);
  for (int i = 1; i <= n; i++) {
    a[i] = lower_bound(pos + 1, pos + n + 1, a[i]) - pos;
    t[a[i]]++;
  }
  for (int i = 1; i <= n; i++)
    if (t[i]) q.push((pair<int, int>){t[i], i});
  int x = 0;
  while (1) {
    int flag = 1;
    for (int k = 0; k < 3; k++) {
      if (q.empty()) {
        flag = 0;
        break;
      }
      int i = q.top().second;
      q.pop();
      b[x][k] = i;
    }
    if (!flag) break;
    for (int k = 0; k < 3; k++) {
      int i = b[x][k];
      t[i]--;
      if (t[i] > 0) q.push((pair<int, int>){t[i], i});
      b[x][k] = pos[i];
    }
    sort(b[x], b[x] + 3);
    x++;
  }
  printf("%d\n", x);
  for (int i = 0; i < x; i++) printf("%d %d %d\n", b[i][2], b[i][1], b[i][0]);
  return 0;
}
