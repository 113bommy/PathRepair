#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  long long ans = 0;
  int i = 1;
  for (int i = 0; i < k && 2 * (n - 1 - 2 * i) - 1 >= 0; i++) {
    ans += 2 * (n - 1 - 2 * i) - 1;
  }
  printf("%I64d", ans);
  return 0;
}
