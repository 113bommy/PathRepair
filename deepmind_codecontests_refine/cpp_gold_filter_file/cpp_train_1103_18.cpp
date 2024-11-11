#include <bits/stdc++.h>
using namespace std;
int a[100001];
int sum = 0;
int n;
int main() {
  scanf("%d", &n);
  char c[100001];
  scanf("%s", c);
  for (int i = 0; i < strlen(c); i++) {
    a[i] = c[i] - '0';
    sum += a[i];
  }
  if (sum >= n) {
    printf("0");
    return 0;
  }
  std::sort(a, a + strlen(c));
  int cnt = 0;
  int l = strlen(c);
  for (int i = 0; i < l; i++) {
    sum += 9 - a[i];
    cnt++;
    if (sum >= n) {
      printf("%d", cnt);
      return 0;
    }
  }
  return 0;
}
