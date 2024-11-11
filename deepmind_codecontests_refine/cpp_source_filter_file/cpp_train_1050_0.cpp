#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  for (; !isdigit(ch); ch = getchar())
    if (ch == '-') f = -1;
  for (; isdigit(ch); ch = getchar()) x = x * 10 + ch - '0';
  return x * f;
}
const int N = 1000005;
struct Node {
  int a, b;
} A[N];
int Num[N], fa[N], fir[N], sec[N], tag[N];
int find(int x) { return x == fa[x] ? x : fa[x] = find(fa[x]); }
int main() {
  int n = read(), cnt = 0;
  for (int i = 1; i <= n; ++i) {
    A[i].a = read(), A[i].b = read();
    Num[++cnt] = A[i].a, Num[++cnt] = A[i].b;
  }
  sort(Num + 1, Num + cnt + 1);
  int lim = cnt;
  cnt = 1;
  for (int i = 1; i <= lim; ++i)
    if (Num[i] != Num[cnt]) Num[++cnt] = Num[i];
  for (int i = 1; i <= n; ++i) {
    A[i].a = lower_bound(Num + 1, Num + cnt + 1, A[i].a) - Num;
    A[i].b = lower_bound(Num + 1, Num + cnt + 1, A[i].b) - Num;
  }
  for (int i = 1; i <= cnt; ++i) fa[i] = i, fir[i] = Num[i];
  for (int i = 1; i <= n; ++i) {
    int u = find(A[i].a), v = find(A[i].b);
    if (u != v) {
      fa[v] = u;
      tag[u] |= tag[v];
      if (fir[v] > fir[u])
        sec[u] = max(fir[u], sec[v]), fir[u] = fir[v];
      else
        sec[u] = max(sec[u], fir[v]);
    } else if (tag[u]) {
      puts("-1");
      return 0;
    } else
      tag[u] = 1;
  }
  int Ans = 0;
  for (int i = 1; i <= n; ++i) {
    if (i == find(i)) {
      if (tag[i])
        Ans = max(Ans, fir[i]);
      else
        Ans = max(Ans, sec[i]);
    }
  }
  cout << Ans;
  return 0;
}
