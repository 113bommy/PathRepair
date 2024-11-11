#include <bits/stdc++.h>
using namespace std;
queue<int> que[65];
int n, ans[100005], top;
bool flag;
long long now, b[100005];
int main() {
  scanf("%d", &n);
  for (register int i = 1; i <= n; i++) {
    scanf("%lld", &b[i]);
    for (register int j = 60; j >= 0; j--) {
      if (((b[i] >> j) & 1) == 1) {
        que[j].push(i);
        break;
      }
    }
  }
  for (register int i = 1; i <= n; i++) {
    flag = false;
    for (register int j = 0; j <= 60; j++) {
      if (((now >> j) & 1) == 0 && que[j].empty() == false) {
        flag = true;
        top++;
        ans[top] = que[j].front();
        que[j].pop();
        now ^= b[ans[top]];
        break;
      }
    }
    if (flag == false) {
      printf("No\n");
      return 0;
    }
  }
  if (top != n) {
    printf("No\n");
    return 0;
  }
  printf("YES\n");
  for (register int i = 1; i < n; i++) {
    printf("%lld ", b[ans[i]]);
  }
  printf("%lld\n", b[ans[n]]);
  return 0;
}
