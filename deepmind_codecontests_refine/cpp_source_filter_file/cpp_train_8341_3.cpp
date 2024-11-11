#include <bits/stdc++.h>
using namespace std;
int n, a[300005], pre[300005], num[1100000][2];
long long ans;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    pre[i] = pre[i - 1] ^ a[i];
  }
  num[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    ans += num[pre[i]][i & 1];
    num[pre[i]][i & 1]++;
  }
  printf("%d\n", ans);
}
