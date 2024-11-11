#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 9;
const long long mod = 998244353;
int a[N], stk[N], stk2[N], top, top2, t[N], b[N], c[N], ans[N][3], ans2[N][4];
set<int> s;
bool cmp(int u, int v) { return a[u] < a[v]; }
bool cmp2(int u, int v) { return a[u] > a[v]; }
int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = (1); i < (n + 1); ++i) scanf("%d", &a[i]);
  s.insert(n + 1);
  int r1 = 0, r2 = 0;
  for (int i = (n + 1) - 1; i >= (1); --i) {
    while (top) {
      int p = stk[top];
      if (a[p] > a[i]) {
        --top;
        --t[p];
        if (!t[p]) s.insert(p);
        r1 = 0;
      } else {
        break;
      }
    }
    while (top2) {
      int p = stk2[top2];
      if (a[p] < a[i]) {
        --top2;
        --t[p];
        if (!t[p]) s.insert(p);
        r2 = 0;
      } else {
        break;
      }
    }
    b[i] = i + max(r1, r2) + 1;
    ans[i][0] = i, ans[i][1] = b[i] - 1, ans[i][2] = b[i];
    int s1 = lower_bound(stk + 1, stk + 1 + top, i, cmp) - stk - 1,
        s2 = lower_bound(stk2 + 1, stk2 + 1 + top2, i, cmp2) - stk2 - 1;
    if (s1 & s2) {
      c[i] = *s.lower_bound(max(stk[s1], stk2[s2]));
      if (c[i] <= n) {
        int u = lower_bound(stk + 1, stk + 1 + top, c[i], greater<int>()) - stk,
            v = lower_bound(stk2 + 1, stk2 + 1 + top2, c[i], greater<int>()) -
                stk2;
        ans2[i][0] = i;
        ans2[i][1] = min(stk[u], stk2[v]);
        ans2[i][2] = max(stk[u], stk2[v]);
        ans2[i][3] = c[i];
      }
    } else
      c[i] = n + 1;
    stk[++top] = i;
    stk2[++top2] = i;
    ++r1, ++r2;
    t[i] += 2;
    if (i < n && b[i] > b[i + 1]) {
      b[i] = b[i + 1];
      for (int j = (0); j < (3); ++j) ans[i][j] = ans[i + 1][j];
    }
    if (i < n && c[i] > c[i + 1]) {
      c[i] = c[i + 1];
      for (int j = (0); j < (4); ++j) ans2[i][j] = ans2[i + 1][j];
    }
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (c[l] <= r) {
      printf("4\n");
      for (int i = (0); i < (4); ++i) printf("%d ", ans2[l][i]);
    } else if (b[l] <= r) {
      printf("3\n");
      for (int i = (0); i < (3); ++i) printf("%d ", ans[l][i]);
    } else
      printf("0");
    printf("\n");
  }
}
