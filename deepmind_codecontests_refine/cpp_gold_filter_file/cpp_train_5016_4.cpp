#include <bits/stdc++.h>
using namespace std;
int n, k, x[200005], y[200005], z[200005], w[200005];
char ans[200005];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    x[tmp] = i;
    w[i] = tmp - 1;
  }
  for (int i = 0; i < n; i++) {
    int tmp;
    scanf("%d", &tmp);
    y[tmp] = i;
  }
  for (int i = 1; i <= n; i++) {
    int ta = min(x[i], y[i]);
    int tb = max(x[i], y[i]);
    z[ta + 1]++;
    z[tb + 1]--;
  }
  ans[w[0]] = 'a';
  k = 'a' + k - 1;
  for (int i = 1; i < n; i++) {
    z[i] += z[i - 1];
    if (z[i] == 0 && ans[w[i - 1]] != k)
      ans[w[i]] = ans[w[i - 1]] + 1;
    else
      ans[w[i]] = ans[w[i - 1]];
  }
  if (ans[w[n - 1]] == k)
    printf("YES\n%s\n", ans);
  else
    puts("NO");
}
