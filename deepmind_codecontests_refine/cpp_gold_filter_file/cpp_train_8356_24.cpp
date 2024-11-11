#include <bits/stdc++.h>
using namespace std;
int c[8];
int flag = 0;
void solve(int n, int k) {
  if (flag == 1) return;
  if (k == 3) {
    if (n % k == 0) {
      c[3] = n / k;
      flag = 1;
    } else
      return;
  }
  for (int i = 0; i <= n / k; i++) {
    if (flag == 1) return;
    solve(n - (i * k), k - 2);
    c[k] = i;
  }
}
int main() {
  int t, n;
  cin >> t;
  while (t--) {
    flag = 0;
    memset(c, 0, sizeof(c));
    cin >> n;
    solve(n, 7);
    if (flag == 1)
      std::cout << c[3] << " " << c[5] << " " << c[7] << std::endl;
    else
      cout << -1 << endl;
  }
  return 0;
}
