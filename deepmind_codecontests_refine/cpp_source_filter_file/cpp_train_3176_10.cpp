#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n, t;
  cin >> n >> t;
  if (n == 1 && t == 10) {
    printf("-1\n");
    return 0;
  }
  if (t == 10) {
    for (int i = 1; i <= n - 1; i++) printf("1");
    printf("0\n");
    return 0;
  } else {
    for (int i = 1; i <= n; i++) printf("t");
    printf("\n");
    return 0;
  }
}
