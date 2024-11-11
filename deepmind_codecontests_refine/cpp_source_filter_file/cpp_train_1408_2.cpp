#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m;
  cin >> n >> m;
  if (n == 0) {
    cout << m * 3;
    return 0;
  }
  if (m == 0) {
    cout << n * 2;
    return 0;
  }
  long long max1, max2;
  long long i = 3;
  long long j = 2;
  long long ans;
  max1 = n * 2;
  max2 = m * 3;
  if (i * 2 <= max1 && j * 3 <= max2) {
    if (max1 + 2 <= max2 + 3) {
      max1 += 2;
    } else
      max2 += 3;
    i += 3;
    j += 2;
  }
  ans = (max1 >= max2 ? max1 : max2);
  cout << ans;
  return 0;
}
