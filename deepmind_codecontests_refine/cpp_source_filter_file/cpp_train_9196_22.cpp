#include <bits/stdc++.h>
using namespace std;
int n, k;
const int N = 1e5 + 9;
char s[2][N];
struct P {
  int x, y, w;
} now, nex, a;
bool bfs() {
  queue<P> q;
  a.x = 0, a.y = 0, a.w = 0;
  s[a.x][a.y] = 'X';
  q.push(a);
  while (!q.empty()) {
    now = q.front();
    q.pop();
    if (now.y >= n) {
      return 1;
    }
    for (int i = 0; i < 3; i++) {
      if (i == 0) {
        nex.x = now.x, nex.y = now.y - 1;
      }
      if (i == 1) {
        nex.x = now.x, nex.y = now.y + 1;
      }
      if (i == 2) {
        nex.x = 1 - now.x, nex.y = now.y + k;
      }
      nex.w = now.w + 1;
      if (nex.x >= 0 && nex.x <= 1 && nex.y >= 0 && nex.w <= nex.y &&
          s[nex.x][nex.y] != 'X') {
        s[nex.x][nex.y] = 'X';
        q.push(nex);
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &k);
  scanf("%s%s", s[0], s[1]);
  if (bfs()) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
}
