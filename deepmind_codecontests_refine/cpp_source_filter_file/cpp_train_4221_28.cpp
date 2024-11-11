#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  scanf("%d", &n);
  while (n > 0) {
    if (n % 10 == 1) ans++;
    n /= 10;
  }
  printf("%d\n", ans);
}
