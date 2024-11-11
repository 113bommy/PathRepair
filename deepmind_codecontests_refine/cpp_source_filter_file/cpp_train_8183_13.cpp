#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n;
  cin >> n;
  long long int lp = n;
  long long int res = 1;
  long long int i;
  long long int x;
  long long int flag[n + 1];
  for (i = 1; i <= n; i++) {
    flag[i] = 0;
  }
  cout << res;
  for (i = 1; i <= n; i++) {
    res = 1;
    cin >> x;
    flag[x] = 1;
    while (flag[lp] != 0) lp--;
    res += lp - n + i;
    cout << " " << res;
  }
}
