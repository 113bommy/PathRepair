#include <bits/stdc++.h>
using namespace std;
int prime[200000];
bool bo[1000001];
int prime_table() {
  int i, j, flag = 0;
  memset(bo, 0, sizeof(bo));
  bo[0] = bo[1] = 1;
  for (i = 2; i <= 1000; i++)
    if (!bo[i]) {
      j = i * i;
      for (; j <= 1000000; j += i) bo[j] = 1;
    }
  for (i = 0; i <= 1000000; i++)
    if (!bo[i]) prime[flag++] = i;
  return flag;
}
int rev(int a) {
  int res = 0, tmp;
  while (a) {
    res *= 10;
    tmp = a % 10;
    a /= 10;
    res += tmp;
  }
  return res;
}
int main() {
  int flag = prime_table();
  int cnt = 0;
  int n;
  scanf("%d", &n);
  for (int i = 5; i < flag; i++) {
    if (!bo[rev(prime[i])] && !rev(prime[i]) == prime[i]) cnt++;
    if (cnt == n) {
      printf("%d\n", prime[i]);
      break;
    }
  }
  return 0;
}
