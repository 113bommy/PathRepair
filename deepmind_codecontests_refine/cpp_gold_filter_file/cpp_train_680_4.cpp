#include <bits/stdc++.h>
using namespace std;
int a[505], b[505];
int pre[505];
long long s[505];
pair<int, char> ans[505];
int main() {
  int n, k;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    s[i] = s[i - 1] + a[i];
  }
  scanf("%d", &k);
  long long tmp = 0;
  for (int i = 1; i <= k; i++) {
    scanf("%d", &b[i]);
    tmp += b[i];
  }
  if (tmp != s[n]) {
    printf("NO\n");
    return 0;
  }
  long long sum = 0;
  int cnt = 0;
  for (int i = 1; i <= k; i++) {
    sum += b[i];
    int t = lower_bound(s + 1, s + 1 + n, sum) - s;
    pre[i] = t;
    if (s[pre[i]] - s[pre[i - 1]] != b[i]) {
      printf("NO\n");
      return 0;
    }
    int num = 0;
    long long tsum = 0;
    for (int j = pre[i - 1] + 1; j < pre[i]; j++) {
      tsum += a[j];
      if (a[j] == a[j + 1])
        num++;
      else if (j + 2 <= pre[i] && a[j + 1] + tsum == a[j + 2])
        num++;
      else if (a[j] < a[j + 1]) {
        ans[cnt++] = make_pair(i + 1 + num, 'L');
        while (num) {
          ans[cnt++] = make_pair(i + num, 'L');
          num--;
        }
        a[j + 1] += tsum;
        tsum = 0;
        num = 0;
      } else if (a[j] > a[j + 1]) {
        ans[cnt++] = make_pair(i + num, 'R');
        while (num) {
          ans[cnt++] = make_pair(i + num, 'L');
          num--;
        }
        a[j + 1] += tsum;
        num = 0;
        tsum = 0;
      }
    }
    if (num > 0) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 0; i < cnt; i++) printf("%d %c\n", ans[i].first, ans[i].second);
  return 0;
}
