#include <bits/stdc++.h>
using namespace std;
const int M = 100005;
int read() {
  int x = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
  return x * flag;
}
int n, m, k, sum, ans = 0x3f3f3f3f, tr[M], s[M];
vector<int> g[M], h[M];
void ins(int i, int l, int r, int id, int f) {
  tr[i] += f;
  if (l == r) {
    s[i] += f * l;
    return;
  }
  int mid = (l + r) >> 1;
  if (mid >= id)
    ins(i << 1, l, mid, id, f);
  else
    ins(i << 1 | 1, mid + 1, r, id, f);
  s[i] = s[i << 1] + s[i << 1 | 1];
}
int ask(int i, int l, int r, int k) {
  if (k == 0) return 0;
  if (l == r) return l * k;
  int mid = (l + r) >> 1;
  if (tr[i << 1] >= k) return ask(i << 1, l, mid, k);
  return s[i << 1] + ask(i << 1 | 1, mid + 1, r, k - tr[i << 1]);
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) {
    int a = read(), b = read();
    g[a].push_back(b);
    m = max(m, a);
    if (!a)
      k++;
    else
      ins(1, 0, 10000, b, 1);
  }
  for (int i = 1; i <= m; i++) {
    sort(g[i].begin(), g[i].end());
    reverse(g[i].begin(), g[i].end());
    for (int j = 0; j < g[i].size(); j++) h[j].push_back(g[i][j]);
  }
  for (int i = n; i >= 0; i--) {
    for (int j = 0; j < h[i].size(); j++) {
      k++;
      sum += h[i][j];
      ins(1, 0, 10000, h[i][j], -1);
    }
    ans = min(ans, sum + ask(1, 0, 10000, max(0, i - k + 1)));
  }
  printf("%d\n", ans);
}
