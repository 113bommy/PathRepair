#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  scanf("%d", &n);
  while (n > 0) {
    if (n % 8 == 1) ans++;
    n /= 8;
  }
  printf("%d\n", ans);
}
