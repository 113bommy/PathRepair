#include <bits/stdc++.h>
using namespace std;
bool vis[50];
inline void out(int a) {
  cout << a << endl;
  fflush(stdout);
}
inline bool judge(int a, bool b) {
  if (a == -2) exit(0);
  if (b) {
    if (a > 0)
      return 0;
    else
      return 1;
  } else {
    if (a < 0)
      return 0;
    else
      return 1;
  }
}
int main() {
  int m, n, op;
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    out(1);
    cin >> op;
    if (op == 0) exit(0);
    if (op == 1)
      vis[i] = 1;
    else if (op == -1)
      vis[i] = 0;
    else if (op == -2)
      exit(0);
  }
  int l = 1, r = m, now = 0;
  while (l <= m) {
    now++;
    if (now > n) now = 1;
    int mid = (l + r) >> 1;
    out(mid);
    cin >> op;
    if (op == 0) exit(0);
    if (judge(op, vis[now]))
      r = mid - 1;
    else
      l = mid + 1;
  }
  return 0;
}
