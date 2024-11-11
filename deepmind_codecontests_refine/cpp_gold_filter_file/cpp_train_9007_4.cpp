#include <bits/stdc++.h>
using namespace std;
const int N = 1000010;
int pre[N], nxt[N], a1[N], b1[N];
int top, vis[N];
int main() {
  string s, s1;
  int n, m, pos;
  cin >> n >> m >> pos;
  cin >> s >> s1;
  for (int i = 0; i < n; i++) {
    pre[i] = i - 1, nxt[i] = i + 1;
    if (s[i] == '(')
      b1[++top] = i;
    else {
      a1[i] = b1[top];
      a1[b1[top]] = i;
      top--;
    }
  }
  --pos;
  for (int i = 0; i < m; i++) {
    int x, y;
    if (s1[i] == 'L')
      pos = pre[pos];
    else if (s1[i] == 'R')
      pos = nxt[pos];
    else {
      if (s[pos] == '(') {
        x = pre[pos];
        y = nxt[a1[pos]];
      } else {
        x = pre[a1[pos]];
        y = nxt[pos];
      }
      nxt[x] = y;
      pre[y] = x;
      if (y >= n - 1)
        pos = x;
      else
        pos = y;
      vis[x + 1] += 1, vis[y - 1] -= 1;
    }
  }
  int sum = 0;
  for (int i = 0; i < n; i++) {
    sum += vis[i];
    if (!sum && !vis[i]) cout << s[i];
  }
  cout << "\n";
  return 0;
}
