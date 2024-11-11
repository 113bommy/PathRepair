#include <bits/stdc++.h>
using namespace std;
const int mod7 = 1000000007;
int arr[2000000];
int val(int c) {
  switch (c % 4) {
    case 0:
      return c;
    case 1:
      return 1;
    case 2:
      return c + 1;
    case 3:
      return 0;
    default:
      return 0;
  }
  return 0;
}
int main() {
  int n, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    ans = ans ^ arr[i];
    int b = n / i;
    int c = n % i;
    if (b & 1) ans = ans ^ val(i);
    ans = ans ^ val(c);
  }
  printf("%d", ans);
  return 0;
}
