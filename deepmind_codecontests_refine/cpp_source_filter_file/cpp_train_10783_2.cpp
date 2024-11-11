#include <bits/stdc++.h>
using namespace std;
long long arr[100100], n, ans, temp, l, r, m;
int main() {
  cin >> n >> m;
  if (n <= m)
    cout << n << endl;
  else {
    ans = m;
    temp = ceil(sqrt((n - m) * 8 + 1));
    ans += ceil((temp - 1) / (double)2.0000);
    cout << ans << endl;
  }
  return 0;
}
