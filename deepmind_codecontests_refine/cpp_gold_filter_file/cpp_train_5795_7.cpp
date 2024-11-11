#include <bits/stdc++.h>
using namespace std;
bool life[100005];
int num[100005];
int pre[100005];
int main() {
  int now = 0, temp = 0;
  int n;
  long long ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
    pre[i] = now;
    now = i;
    while (num[i] + 1 > temp) {
      temp++;
      life[now] = 1;
      now = pre[now];
    }
  }
  temp = 0;
  for (int i = 1; i <= n; i++) {
    if (life[i]) temp++;
    ans += temp - 1 - num[i];
  }
  printf("%lld\n", ans);
  return 0;
}
