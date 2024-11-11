#include <bits/stdc++.h>
const int mod = 1e9 + 7;
int n;
int a[100050];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int l = 0;
  int num = 0, cnt;
  while (a[l] == a[0] && l < n) {
    l++;
    num++;
  }
  l = 0;
  while (l < n) {
    cnt = 0;
    int tmp = a[l];
    while (a[l] == tmp && l < n) {
      l++;
      cnt++;
    }
    if (cnt != num) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  return 0;
}
