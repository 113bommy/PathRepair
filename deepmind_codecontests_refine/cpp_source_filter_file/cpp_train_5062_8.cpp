#include <bits/stdc++.h>
using namespace std;
vector<int> G[100005];
int a[100005], b[100005], pre, len, c, p[100005], n, m, s, t, f, v[100005];
void D(int x) {
  p[c++] = x;
  v[x] = 1;
  f |= x == t;
  for (int x : G[x])
    if (!v[x]) D(x);
}
int main() {
  cin >> n >> m;
  t = m + 1;
  cin >> pre;
  for (int i = 1; i <= pre; i++) cin >> a[i];
  for (int i = 2; i <= n; i++) {
    cin >> len;
    for (int i = 1; i <= len; i++) cin >> b[i];
    int q = 1;
    while (a[q] == b[q] && q <= len) q++;
    if (q <= pre && q > len) exit(puts("No"));
    if (q <= pre && q <= len) {
      if (a[q] > b[q])
        G[s].push_back(a[q]), G[b[q]].push_back(t);
      else
        G[b[q]].push_back(a[q]);
    }
    pre = len;
    for (int i = 1; i <= len; i++) a[i] = b[i];
  }
  D(s);
  if (f)
    puts("No");
  else {
    puts("Yes");
    printf("%d\n", c - 1);
    for (int i = 1; i < c; i++) printf("%d ", p[i]);
  }
}
