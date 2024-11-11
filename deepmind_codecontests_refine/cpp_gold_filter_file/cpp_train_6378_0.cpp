#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 100;
int n, m, last[N], jump[N], a[N], np;
void solve(int ind) {
  int ans = 0, en;
  while (ind != -1) {
    en = ind;
    if (last[ind] == ind) {
      ans++;
      if (ind + a[ind] >= n)
        ind = -1;
      else
        ind += a[ind];
    } else {
      ans += jump[ind];
      ind = last[ind];
    }
  }
  printf("%d %d\n", en + 1, ans);
}
void build(int b, int e) {
  for (int i = e - 1; i >= b; i--) {
    if (a[i] + i >= e)
      last[i] = i, jump[i] = 0;
    else
      last[i] = last[i + a[i]], jump[i] = jump[i + a[i]] + 1;
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  np = 1;
  while (np * np < n) np++;
  for (int i = 0; i < np; i++) build(i * np, min((i + 1) * np, n));
  for (int i = 0; i < m; i++) {
    int t, ind, b;
    scanf("%d", &t);
    if (!t) {
      scanf("%d %d", &ind, &b);
      a[--ind] = b;
      build((ind / np) * np, min(n, (ind / np + 1) * np));
    } else {
      scanf("%d", &ind);
      solve(--ind);
    }
  }
}
