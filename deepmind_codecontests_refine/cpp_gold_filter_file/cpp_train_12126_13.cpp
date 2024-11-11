#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, m, E, cnt;
int ans[N], fir[N], nex[N], arr[N], deg[N], use[200][200];
string s[N];
queue<int> Q;
inline void Add_Edge(int x, int y) {
  if (use[x][y]) return;
  use[x][y] = 1;
  nex[++E] = fir[x];
  fir[x] = E;
  arr[E] = y;
  deg[y]++;
}
void check(int x, int y) {
  int l = 0;
  while (l < s[x].size() && l < s[y].size()) {
    if (s[x][l] != s[y][l]) {
      Add_Edge(s[x][l], s[y][l]);
      return;
    }
    l++;
  }
  if (s[x].size() > s[y].size()) {
    puts("Impossible");
    exit(0);
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      check(i, j);
    }
  }
  for (int i = 'a'; i <= 'z'; i++)
    if (deg[i] == 0) Q.push(i);
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    ans[++cnt] = x;
    for (int i = fir[x]; i; i = nex[i]) {
      if (--deg[arr[i]] == 0) Q.push(arr[i]);
    }
  }
  if (cnt < 26) return 0 * puts("Impossible");
  for (int i = 1; i <= cnt; i++) putchar(ans[i]);
  puts("");
  return 0;
}
