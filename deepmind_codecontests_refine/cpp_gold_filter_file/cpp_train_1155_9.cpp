#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a;
  long long i, ans = 0;
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%d", &a);
    ans += i * (a - 1);
  }
  cout << ans + n;
}
