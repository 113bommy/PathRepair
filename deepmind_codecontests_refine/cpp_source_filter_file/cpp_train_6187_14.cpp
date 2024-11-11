#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long ans = 0;
  cin >> n;
  if (n == 0) {
    puts("1");
    return 0;
  }
  double r1 = n, r2;
  long long tmp = n, k;
  for (int i = 1; i <= n; i++) {
    r2 = i;
    k = (long long)sqrt(r1 * r1 - r2 * r2);
    if (tmp == k) {
      ans++;
    } else {
      ans + tmp - k;
    }
    tmp = k;
  }
  cout << ans * 4;
  return 0;
}
