#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int odd = 0, even = 0;
  int sum = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      odd++;
    else
      even++;
    sum += x;
  }
  if (sum & 1) {
    printf("%d\n", odd);
    return 0;
  }
  printf("%d\n", even);
  return 0;
}
