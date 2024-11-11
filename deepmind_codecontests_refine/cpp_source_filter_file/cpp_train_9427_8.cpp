#include <bits/stdc++.h>
using namespace std;
int cnt[103];
char str[103];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", str);
    cnt[strlen(str)]++;
  }
  scanf("%s", str);
  int target = (int)strlen(str);
  int sum = 0;
  for (int i = 1; i < target; i++) {
    sum += cnt[i];
  }
  printf("%d ", sum + 1 + 5 * (sum / k));
  printf("%d\n", sum + cnt[target] + 5 * (sum + cnt[target] - 1) / k);
  return 0;
}
