#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1, c = getchar();
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) {
    x = (x << 1) + (x << 3) + (c ^ 48);
    c = getchar();
  }
  return f == 1 ? x : -x;
}
const int N = 1e6 + 4;
int n, m, nw = 1, a[N], L[N], R[N], nxt[N], vis[N];
inline void NO(int fl) {
  cerr << fl << " wrong\n";
  puts("no");
  exit(0);
}
inline void del(int l, int r) {
  R[L[l]] = R[r];
  L[R[r]] = L[l];
}
inline int newnode() {
  while (vis[nw]) nw++;
  if (nw > n) NO(1);
  return nw++;
}
void solve(int l, int r) {
  if ((r - l) & 1) NO(2);
  for (int i = l; i <= r; i = R[i]) {
    while (nxt[i]) {
      if (nxt[i] > r) NO(3);
      solve(R[i], L[nxt[i]]);
      del(R[i], nxt[i]);
      nxt[i] = nxt[nxt[i]];
    }
  }
  int sum = 0, cou = 0, rt = a[L[l]];
  for (int i = l; i <= r; i = R[i]) {
    sum++;
    cou += (a[i] > 0);
  }
  sum = (sum + 1) / 2;
  if (cou > sum) NO(4);
  for (int i = R[l]; i <= r && cou < sum; i = R[i])
    if (!a[i]) {
      a[i] = newnode();
      cou++;
    }
  if (sum == 1 && !cou) a[l] = newnode();
  for (int i = l; R[i] <= r; i = R[i]) {
    while (i > l && R[i] <= r && !a[L[i]] && a[i] && a[R[i]]) {
      a[L[i]] = a[R[i]];
      del(i, R[i]);
      i = L[L[i]];
    }
    while (i >= l && R[R[i]] <= r && a[i] && a[R[i]] && !a[R[R[i]]]) {
      a[R[R[i]]] = a[i];
      del(R[i], R[R[i]]);
      i = L[i];
    }
  }
  for (int i = l; i <= r; i = R[i])
    if (!a[i]) a[i] = rt;
}
int main() {
  n = read();
  m = (n << 1) - 1;
  for (int i = 1; i <= m; i++) {
    a[i] = read();
    L[i] = i - 1;
    R[i] = i + 1;
  }
  R[m + 1] = m + 1;
  L[m + 1] = m;
  R[0] = 1;
  if (a[1] && a[m] && a[1] != a[m]) NO(5);
  a[1] = a[m] = (a[1] | a[m]);
  for (int i = m; i; i--)
    if (a[i]) {
      nxt[i] = vis[a[i]];
      vis[a[i]] = i;
    }
  solve(1, m);
  puts("yes");
  for (int i = 1; i <= m; i++) cout << a[i] << " ";
  return (0 - 0);
}
