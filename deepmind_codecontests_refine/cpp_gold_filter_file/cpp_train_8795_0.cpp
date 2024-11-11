#include <bits/stdc++.h>
using namespace std;
int s[123];
int main() {
  int n;
  scanf("%d", &n);
  int a;
  memset(s, 0, sizeof(s));
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    if (i == 0)
      s[i] = a;
    else
      s[i] = a - s[0];
  }
  s[0] = 0;
  int sum = 0;
  int flag = 0;
  for (int j = 0;; j++) {
    sort(s + 1, s + n);
    if (s[n - 1] >= s[0]) {
      s[n - 1]--;
      s[0]++;
      sum++;
    } else
      break;
  }
  printf("%d\n", sum);
  return 0;
}
