#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  int tmp, ans = 0;
  int ini = 1;
  for (int i = 0; i < m; i++) {
    cin >> tmp;
    if (tmp >= ini)
      ans = ans + ((tmp - ini));
    else
      ans = ans + (tmp + n - ini);
    ini = tmp;
  }
  cout << ans;
  return 0;
}
