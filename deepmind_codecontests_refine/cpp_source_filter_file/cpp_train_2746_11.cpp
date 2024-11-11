#include <bits/stdc++.h>
using namespace std;
long long now[8] = {1, 1, 3, 19, 225, 3441, 75259, 2424195};
int main() {
  int n;
  scanf("%d", &n);
  if (n % 2 == 0) {
    puts("0");
    return 0;
  }
  long long ans = now[n / 2] * n % 1000000007;
  for (int i = 2; i <= n; i++) ans = ans * i % 1000000007;
  cout << ans << endl;
  return 0;
}
