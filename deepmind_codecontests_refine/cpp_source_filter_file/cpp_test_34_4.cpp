#include <bits/stdc++.h>
using namespace std;
const int N = 8192;
const int maxn = 2e5 + 10;
const int mod = 1e9 + 7;
inline int read() {
  int x = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
vector<int> v[N];
int n, m, a[maxn], b[N], st[N], rec[N], ans;
int main() {
  n = read();
  ans = st[0] = 1;
  for (int i = 0; i < N; i++) v[i].push_back(0), rec[i] = N - 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    for (auto x : v[a[i]]) {
      int u = x ^ a[i];
      if (!st[u]) st[u] = 1, ++ans;
      if (a[i] <= rec[u]) {
        for (int j = a[i] + 1; j <= rec[u]; j++) v[j].push_back(u);
        rec[u] = a[i] - 1;
      }
    }
    v[a[i]].clear();
  }
  printf("%d\n", ans);
  for (int i = 0; i < N; i++)
    if (st[i]) printf("%d ", i);
  return 0;
}
