#include <bits/stdc++.h>
using namespace std;
int num[100000 + 10];
int s1[100000 + 10];
int s2[100000 + 10];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num[i]);
  }
  s1[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (num[i] >= num[i - 1])
      s1[i] = s1[i - 1] + 1;
    else
      s1[i] = 1;
  }
  s2[n] = 1;
  for (int i = n - 1; i; i--) {
    if (num[i] < num[i + 1])
      s2[i] = s2[i + 1] + 1;
    else
      s2[i] = 1;
  }
  int ans = 1;
  for (int i = 2; i <= n; i++) {
    if (num[i - 1] + 2 <= num[i + 1]) {
      if (s1[i - 1] + s2[i + 1] + 1 > ans) ans = s1[i - 1] + s2[i + 1] + 1;
    }
  }
  for (int i = 2; i <= n; i++) {
    ans = max(ans, s1[i - 1] + 1);
  }
  for (int i = 1; i <= n; i++) {
    ans = max(ans, s2[i + 1] + 1);
  }
  printf("%d\n", ans);
}
