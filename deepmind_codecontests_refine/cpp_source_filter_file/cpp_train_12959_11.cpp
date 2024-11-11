#include <bits/stdc++.h>
using namespace std;
long long sum[200010];
int num[200010];
int n, m;
int main() {
  while (scanf("%d", &n) == 1) {
    memset(sum, 0, sizeof(sum));
    for (int i = 1; i <= n; i++) {
      scanf("%I64d", &sum[i]);
      if (i > 1) sum[i] -= sum[1];
    }
    sum[1] = 0;
    int min_num = 0x3f3f3f3f;
    scanf("%d", &m);
    int m1 = m;
    int x;
    memset(num, 0, sizeof(num));
    while (m1--) {
      scanf("%d", &x);
      num[x]++;
    }
    for (int i = 2; i < n; i++) min_num = min(min_num, num[i] / 2);
    min_num = min(min_num, num[1]);
    min_num = min(min_num, num[n]);
    long long ans = 0;
    ans += min_num * 2 * sum[n];
    for (int i = 2; i < n; i++) num[i] = num[i] - min_num * 2;
    num[1] -= min_num;
    num[n] -= min_num;
    int max_num = 0;
    for (int i = 1; i <= n; i++) max_num = max(num[i], max_num);
    if (max_num == 0) {
      if (sum[n] % (n - 1))
        ans = -1;
      else {
        int delta = sum[n] / (n - 1);
        for (int i = 2; i <= n; i++) {
          if (delta != sum[i] - sum[i - 1]) {
            ans = -1;
            break;
          }
        }
        if (ans != -1) ans -= delta;
      }
    } else if (max_num == 1) {
      int sta = 0;
      while (num[sta] != 1) sta++;
      int end = n;
      while (num[end] != 1) end--;
      ans += sum[end] - sum[sta];
    } else if (max_num == 2) {
      if (num[1] == 1 && num[n] == 0) {
        int s1 = 1;
        while (num[s1] >= 1) s1++;
        s1--;
        int s2 = 1;
        while (num[s2] == 2) s1++;
        s2--;
        ans += sum[s1] + sum[s2];
      } else if (num[1] == 0 && num[n] == 1) {
        int s1 = 1;
        while (num[s1] != 2) s1++;
        int s2 = 1;
        while (num[s2] == 0) s2++;
        ans += sum[n] - sum[s1] + sum[n] - sum[s2];
      } else if (num[1] == 1 && num[n] == 1) {
        int st = 2;
        while (num[st] == 2) st++;
        int en = n - 1;
        while (num[en] == 2) en--;
        ans += 2 * sum[n] - (sum[en + 1] - sum[st - 1]);
      }
    }
    printf("%I64d\n", ans);
  }
  return 0;
}
