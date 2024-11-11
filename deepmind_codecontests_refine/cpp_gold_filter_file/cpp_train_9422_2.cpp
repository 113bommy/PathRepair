#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 15;
int n, num, a[maxn];
int main() {
  int len = 1, cnt = 1;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &num);
    a[num - 1] = i;
  }
  for (int i = 1; i < n; i++) {
    if (a[i] > a[i - 1])
      cnt++;
    else
      cnt = 1;
    len = max(len, cnt);
  }
  printf("%d\n", n - len);
  return 0;
}
