#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ans = 0, i, j, b;
  double sq;
  cin >> n;
  for (i = 1; i <= n; i++) {
    b = (int)sqrt(n * n - i * i);
    for (j = i; j <= b; j++) {
      sq = sqrt(i * i + j * j);
      if (sq == (int)sq) {
        ans++;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
