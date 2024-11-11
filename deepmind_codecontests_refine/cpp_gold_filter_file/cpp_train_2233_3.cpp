#include <bits/stdc++.h>
using namespace std;
struct cs {
  int to, next;
} a[200001];
int aa[400001], head[100001], sum[100001];
bool vi[100001], c[100001];
int n, m, z, y, x, ans, ll, S;
void init(int x, int y) {
  a[++ll].to = y;
  a[ll].next = head[x];
  head[x] = ll;
}
void dfs(int x, int y) {
  vi[x] = 1;
  aa[++ans] = x;
  sum[x]++;
  for (int k = head[x]; k; k = a[k].next)
    if (!vi[a[k].to]) {
      dfs(a[k].to, x);
      aa[++ans] = x;
      sum[x]++;
    }
  if (bool(sum[x] & 1) != c[x]) {
    aa[++ans] = y;
    sum[y]++;
    aa[++ans] = x;
    sum[x]++;
  }
}
int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    scanf("%d%d", &x, &y);
    init(x, y);
    init(y, x);
  }
  for (int i = 1; i <= n; i++) {
    cin >> c[i];
    if (c[i]) S = i;
  }
  if (S) {
    dfs(S, -1);
    for (int i = 1; i <= n; i++)
      if (!vi[i] && c[i]) {
        printf("-1");
        return 0;
      }
  }
  if (ans > 1 && aa[ans - 1] == -1) ans -= 3;
  printf("%d\n", ans);
  for (int i = 1; i <= ans; i++) printf("%d ", aa[i]);
}
