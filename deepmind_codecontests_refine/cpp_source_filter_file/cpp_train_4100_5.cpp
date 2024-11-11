#include <bits/stdc++.h>
using namespace std;
int n, k, a, ans, tmp;
int main() {
  ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k >> a;
    if (a == 1)
      tmp = 0;
    else
      tmp = ceil(log((double)a) / log(4.0));
    ans = max(ans, k + tmp);
  }
  cout << ans << '\n';
}
