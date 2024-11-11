#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, k, ans;
  cin >> n >> k;
  long long a, b, c;
  a = n * 2;
  b = n * 5;
  c = n * 8;
  ans = ceil(a / k) + ceil(b / k) + ceil(c / k);
  cout << ans << endl;
  return 0;
}
