#include <bits/stdc++.h>
using namespace std;
inline int gotcha() {
  int a = 0, b = 1, c = getchar();
  while (!isdigit(c)) b ^= c == '-', c = getchar();
  while (isdigit(c)) a = a * 10 + c - 48, c = getchar();
  return b ? a : -a;
}
int main() {
  map<int, int> mp;
  int n;
  scanf("%d", &n);
  int b, i, index = 0, j;
  for (i = 1; i <= n; i++) {
    scanf("%d", &b);
    mp[b] = i;
  }
  for (i = 0; i < n; i++) {
    b = gotcha();
    if (mp[b] - index > 0) {
      printf("%d ", mp[b] - index);
      index = mp[b];
    } else
      printf("0 ");
  }
}
