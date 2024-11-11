#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, a, b, c, ans = 0;
  ;
  cin >> n >> a >> b >> c;
  for (int i = 0; i < 4000; i++)
    for (int j = 0; j < 4000; j++) {
      if ((n - i * a - j * b) < 0) break;
      if ((n - i * a - j * b) % c == 0)
        ans = max(i + j + (n - i * a - j * b) / c, ans);
    }
  cout << ans;
}
