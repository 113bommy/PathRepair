#include <bits/stdc++.h>
using namespace std;
int main() {
  int n = 1, c;
  long long int ans = 1;
  scanf("%d", &c);
  while (ans < c) {
    n++;
    ans = ans + (n * (n + 1) / 2);
  }
  printf("%d", n - 1);
  return 0;
}
