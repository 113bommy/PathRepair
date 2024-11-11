#include <bits/stdc++.h>
using namespace std;
char s1[200005];
char s2[200005];
int sum[200005];
int ans[200005];
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s", s1 + 1);
  scanf("%s", s2 + 1);
  for (int i = 1; i <= n; i++) {
    sum[i] = s1[i] + s2[i] - 'a' - 'a';
  }
  for (int i = n; i >= 1; i--) {
    if (sum[i] > 26 && i != 1) {
      sum[i] -= 26;
      sum[i - 1] += 1;
    }
  }
  for (int i = 1; i <= n; i++) {
    ans[i] = (sum[i] / 2) % 26;
    if (sum[i] % 2 == 1) sum[i + 1] += 26;
  }
  for (int i = 1; i <= n; i++) printf("%c", 'a' + ans[i]);
  printf("\n");
  return 0;
}
