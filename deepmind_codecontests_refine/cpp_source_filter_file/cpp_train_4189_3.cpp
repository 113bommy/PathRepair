#include <bits/stdc++.h>
using namespace std;
int n, t, a[200001], b[200001];
char s[200010];
bool vis1[200011], vis2[200011];
priority_queue<int> q, p;
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    scanf("%s", s + 1);
    memset(vis1, false, sizeof(bool) * (n + 2));
    memset(vis2, false, sizeof(bool) * (n + 2));
    for (int i = 1; i <= n; ++i) {
      if ((i == 1 || s[i - 1] == '>') && (i == n || s[i] == '<'))
        q.push(i), p.push(-i);
    }
    for (int i = 1; i <= n; ++i) {
      int x = q.top();
      q.pop();
      a[x] = i;
      int y = p.top();
      p.pop();
      y = -y;
      b[y] = i;
      vis1[x] = vis2[y] = true;
      if (x != 1) {
        if ((x == 2 || vis1[x - 2] || s[x - 2] == '>') && !vis1[x - 1])
          q.push(x - 1);
      }
      if (x != n) {
        if ((x == n - 1 || vis1[x + 2] || s[x + 1] == '<') && !vis1[x + 1])
          q.push(x + 1);
      }
      if (y != 1) {
        if ((y == 2 || vis2[y - 2] || s[y - 2] == '>') && !vis2[y - 1])
          p.push(1 - y);
      }
      if (y != n) {
        if ((y == n - 1 || vis2[y + 2] || s[y + 1] == '<') && !vis2[y + 1])
          p.push(-1 - y);
      }
    }
    for (int i = 1; i <= n; ++i) printf("%d ", b[i]);
    putchar(10);
    for (int i = 1; i <= n; ++i) printf("%d ", a[i]);
    putchar(10);
  }
  return 0;
}
