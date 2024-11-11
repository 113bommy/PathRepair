#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int n, ans[N], t[N], x[N], op[N], p[N], tmp[N];
map<int, int> num;
int read() {
  int x = 0, f = 1;
  char s;
  while ((s = getchar()) < '0' || s > '9')
    if (s == '-') f = -1;
  while (s >= '0' && s <= '9') {
    x = (x << 1) + (x << 3) + (s ^ 48);
    s = getchar();
  }
  return x * f;
}
bool cmp(const int a, const int b) {
  return (t[a] ^ t[b]) ? t[a] < t[b]
                       : ((x[a] ^ x[b]) ? x[a] < x[b] : op[a] < op[b]);
}
void cdq(const int L, const int R) {
  if (L >= R) return;
  int mid = L + R >> 1;
  cdq(L, mid);
  cdq(mid + 1, R);
  int i = L, j = mid + 1;
  for (int k = L; k <= R; ++k) {
    int p1 = p[i], p2 = p[j];
    if ((i <= mid && cmp(p1, p2)) || j > R) {
      if (op[p1] == 1) ++num[x[p1]];
      if (op[p1] == 2) --num[x[p1]];
      tmp[k] = p[i++];
    } else {
      if (op[p2] == 3) ans[p2] += num[x[p2]];
      tmp[k] = p[j++];
    }
  }
  for (i = L; i <= R; ++i) num[p[i]] = 0, p[i] = tmp[i];
}
int main() {
  n = read();
  for (int i = 1; i <= n; ++i)
    p[i] = i, op[i] = read(), t[i] = read(), x[i] = read();
  cdq(1, n);
  for (int i = 1; i <= n; ++i)
    if (op[i] == 3) printf("%d\n", ans[i]);
  return 0;
}
