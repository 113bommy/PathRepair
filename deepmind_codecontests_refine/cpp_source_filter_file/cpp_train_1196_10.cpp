#include <bits/stdc++.h>
using namespace std;
vector<int> e[100010];
bool isdel[100010], onchain[100010];
int deg[100010], t[100010], q[100010];
namespace input {
int read() {
  char ch;
  for (ch = getchar(); (ch < '0' || ch > '9') && ch != '-';) ch = getchar();
  int d = 0, t = 1;
  if (ch == '-') {
    t = -1;
    ch = getchar();
  }
  for (; ch >= '0' && ch <= '9'; ch = getchar()) d = d * 10 + ch - 48;
  return d * t;
}
}  // namespace input
int main() {
  int n = input::read();
  for (int i = 1; i < n; i++) {
    int x = input::read(), y = input::read();
    e[x].push_back(y);
    e[y].push_back(x);
    deg[x]++;
    deg[y]++;
  }
  memcpy(t + 1, deg + 1, n * sizeof(int));
  int f = 1, r = 0;
  for (int i = 1; i <= n; i++)
    if (t[i] == 1) q[++r] = i;
  while (f <= r) {
    int k = q[f++];
    for (vector<int>::iterator p = e[k].begin(); p != e[k].end(); p++) {
      t[*p]--;
      if (t[*p] == 1 && deg[*p] < 3) q[++r] = (*p);
    }
  }
  memset(isdel, 0, sizeof(isdel));
  for (int i = 1; i <= r; i++) isdel[q[i]] = 1;
  for (int i = 1; i <= n; i++)
    if (!isdel[i]) {
      int s = 0;
      for (vector<int>::iterator p = e[i].begin(); p != e[i].end(); p++)
        if (!isdel[*p]) s = min(s + 1, 2);
      onchain[i] = (deg[i] - s > 1);
    }
  bool ok = 1;
  for (int i = 1; i <= n; i++)
    if (!isdel[i]) {
      int s = 0;
      for (vector<int>::iterator p = e[i].begin(); p != e[i].end(); p++)
        if ((!isdel[*p]) && onchain[*p]) s++;
      if (s > 2) {
        ok = 0;
        break;
      }
    }
  if (ok)
    puts("Yes");
  else
    puts("No");
  return 0;
}
