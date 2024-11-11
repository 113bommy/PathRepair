#include <bits/stdc++.h>
using namespace std;
const int INF = 0x7f7f7f7f;
const int MAXN = 1e6 + 111;
int main() {
  int n, x, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += (1 - x % 2);
    if (sum % 2)
      printf("1\n");
    else
      printf("2\n");
  }
  return 0;
}
