#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
const int inf = (1 << 28) - 1;
int fac[maxn], len;
long long cnt, tot;
int num[maxn];
void get_fac(int x) {
  len = 0;
  for (int i = 2; i * i <= x; ++i)
    if (x % i == 0) {
      fac[++len] = i;
      while (x % i == 0) x /= i;
    }
  if (x > 1) fac[++len] = x;
}
long long res;
void add(int pos, long long val, int flag, int ope) {
  if (pos == len + 1) {
    if (!flag) return;
    if (!ope) num[val]--;
    if (flag % 2)
      res += num[val];
    else
      res -= num[val];
    if (ope) num[val]++;
    return;
  }
  add(pos + 1, val * fac[pos], flag + 1, ope);
  add(pos + 1, val, flag, ope);
}
int A[maxn];
bool vis[maxn];
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  tot = cnt = 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
  while (m--) {
    int x;
    scanf("%d", &x);
    get_fac(A[x]);
    res = 0;
    if (!vis[x]) {
      vis[x] = 1;
      add(1, 1, 0, 1);
      cnt += tot - res;
      tot++;
      printf("%d\n", cnt);
    } else {
      vis[x] = 0;
      add(1, 1, 0, 0);
      tot--;
      cnt -= tot - res;
      printf("%d\n", cnt);
    }
  }
  return 0;
}
