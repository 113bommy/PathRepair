#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, ans;
  long double k;
  cin >> n >> k;
  ans = ceil(8 * n / k) + ceil(5 * n / k) + ceil(2 * n / k);
  cout << ans << endl;
  return 0;
}
