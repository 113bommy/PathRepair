#include <bits/stdc++.h>
using namespace std;
char a[105];
int ans, len;
void solve(int depth, int st, int sum) {
  if (depth == 3) {
    if (st != len) return;
    ans = max(ans, sum);
    return;
  }
  int k = 0;
  for (int i = st; i < len; i++) {
    k = k * 10 + (a[i] - '0');
    if (k > 1e6) break;
    solve(depth + 1, i + 1, sum + k);
    if (a[st] == '0') break;
  }
}
int main() {
  scanf("%s", a);
  len = strlen(a);
  if (len >= 4 && a[0] == '0' && a[1] == '0' && a[2] == '0') {
    printf("-1\n");
    return 0;
  } else if (len > 18) {
    printf("-1\n");
    return 0;
  }
  ans = -1;
  solve(0, 0, 0);
  printf("%d\n", ans);
  return 0;
}
