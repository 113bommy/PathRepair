#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int T, N;
int len;
int q[1000010];
int e[1000010];
int a[1000010];
int t[1000010];
int qu[1000010];
int lowbit(int x) { return x & -x; }
void add(int x, int v) {
  while (x <= len) {
    e[x] += v;
    x += lowbit(x);
  }
}
int query(int x) {
  int sum = 0;
  while (x > 0) {
    sum += e[x];
    x -= lowbit(x);
  }
  return sum;
}
int main() {
  int m, n;
  cin.tie(0);
  while (scanf("%d", &n) != EOF) {
    scanf("%d", &m);
    memset(e, 0, 1000010);
    memset(q, 0, 1000010);
    len = n;
    for (int i = 0; i <= m - 1; i++) scanf("%d", &a[i]);
    int op;
    int j = 0;
    int k = 0;
    int ttt = n;
    while (ttt--) {
      int x;
      scanf("%d", &x);
      if (x < 0) {
        int zs = 0;
        for (int i = 0; i <= m - 1; i++) {
          int l = 0, r = k;
          if (query(k) < a[i]) break;
          while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (query(mid) >= a[i]) {
              r = mid;
            } else {
              l = mid;
            }
          }
          t[zs++] = r;
        }
        for (int i = 0; i <= zs - 1; i++) {
          add(t[i], -1);
        }
      } else {
        q[++k] = x;
        add(k, 1);
      }
    }
    for (int i = 0; i <= k; i++) qu[i] = query(i);
    if (!qu[k])
      printf("Poor stack!\n");
    else {
      for (int i = 1; i <= k; i++)
        if (qu[i] - qu[i - 1]) printf("%d", q[i]);
    }
  }
  return 0;
}
