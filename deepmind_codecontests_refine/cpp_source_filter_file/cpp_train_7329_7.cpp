#include <bits/stdc++.h>
using namespace std;
const int maxn = 101000;
int a[maxn];
char s[maxn];
int sum[maxn];
int ans[maxn];
int stk[maxn];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    scanf("%s", s);
    memset(sum, 0, sizeof(sum));
    memset(ans, 0, sizeof(ans));
    memset(stk, 0, sizeof(stk));
    int idx = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') stk[idx++] = i;
    }
    sum[0] = a[0];
    for (int i = 1; i < n; i++) sum[i] = a[i] + sum[i - 1];
    if (stk[0])
      ans[stk[0]] = max(sum[stk[0] - 1], a[stk[0]]);
    else {
      ans[0] = a[0];
    }
    for (int i = 1; i < idx; i++) {
      ans[stk[i]] = max(a[stk[i]] + ans[stk[i - 1]], sum[stk[i] - 1]);
    }
    printf("%d\n", ans[stk[idx - 1]]);
  }
  return 0;
}
