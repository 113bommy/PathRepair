#include <bits/stdc++.h>
using namespace std;
int main() {
  int m[10];
  int w[10];
  for (int i = 1; i <= 5; i++) cin >> m[i];
  for (int i = 1; i <= 5; i++) cin >> w[i];
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 1; i <= 5; i++)
    ans += max(150 * i, 500 * i - 2 * m[i] * i - 50 * w[i]);
  ans += 100 * a;
  ans -= 100 * b;
  cout << ans << endl;
  return 0;
}
