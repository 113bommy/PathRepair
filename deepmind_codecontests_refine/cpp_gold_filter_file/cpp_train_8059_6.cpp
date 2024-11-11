#include <bits/stdc++.h>
using namespace std;
char s[100005];
int sum[100005];
int in[100005];
int n, w, k;
int main() {
  scanf("%d%d%d", &n, &k, &w);
  scanf("%s", s + 1);
  for (int i = 1; i <= n; i++) {
    if (s[i] == '1')
      sum[i] = sum[i - 1] + 1;
    else
      sum[i] = sum[i - 1];
  }
  for (int i = 1; i <= k; i++) {
    if (s[i] == '1') in[i] = 1;
  }
  for (int i = k + 1; i <= n; i++) {
    if (s[i] == '1')
      in[i] = in[i - k] + 1;
    else
      in[i] = in[i - k];
  }
  int l, r;
  int need, notneed;
  int tmp;
  for (int i = 0; i < w; i++) {
    scanf("%d%d", &l, &r);
    tmp = (r - l + 1) / k;
    need = (tmp - in[r] + in[l - 1]);
    notneed = (sum[r] - sum[l - 1] - in[r] + in[l - 1]);
    printf("%d\n", need + notneed);
  }
  return 0;
}
