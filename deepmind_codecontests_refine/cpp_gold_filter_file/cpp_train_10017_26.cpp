#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%d", &n);
  int even = 0, odd = 0;
  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    if (x & 1)
      odd++;
    else
      even++;
  }
  if (odd & 1)
    printf("%d", odd);
  else
    printf("%d", even);
  return 0;
}
