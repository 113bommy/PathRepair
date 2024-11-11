#include <bits/stdc++.h>
using namespace std;
long long read() {
  long long ans = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') ans = ans * 10 + c - 48, c = getchar();
  return ans;
}
int n;
int a[211], b[211];
char s[211];
int maxn = 0;
int main() {
  n = read();
  scanf("%s", s + 1);
  for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = read();
  for (int t = 0; t <= 100000; ++t) {
    int num = 0;
    for (int i = 1; i <= n; ++i) {
      int x = s[i] - '0';
      if (b[i] > t)
        num += x;
      else {
        int y = (t - b[i]) / a[i] + 1;
        if (y & 1)
          num += x;
        else
          num += (x ^ 1);
      }
    }
    maxn = max(num, maxn);
  }
  printf("%d\n", maxn);
  return 0;
}
