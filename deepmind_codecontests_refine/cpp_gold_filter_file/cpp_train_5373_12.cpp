#include <bits/stdc++.h>
using namespace std;
char s[1005];
int n, k, f[30], cnt;
int main() {
  scanf("%s %d", s, &k);
  n = strlen(s);
  if (k > n) return 0 * printf("impossible\n");
  for (int i = 0; i < n; i++) {
    f[s[i] - 'a']++;
    if (f[s[i] - 'a'] == 1) cnt++;
  }
  printf("%d\n", max(0, k - cnt));
  return 0;
}
