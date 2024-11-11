#include <bits/stdc++.h>
using namespace std;
long long int modpow(long long int a, long long int n, long long int temp) {
  long long int res = 1, y = a;
  while (n > 0) {
    if (n & 1) res = (res * y) % temp;
    y = (y * y) % temp;
    n /= 2;
  }
  return res % temp;
}
int main() {
  long double n, a;
  long double mini = INT_MAX;
  cin >> n >> a;
  long double ang = ((180 * n) - 360) / n;
  long double minang = (180 - ang) / 2;
  long double orminang = minang;
  vector<int> ans(3, 0);
  int i = 0;
  long double diff = 0;
  while (minang < (ang + orminang)) {
    diff = abs(minang - a);
    if (diff <= mini) {
      ans[0] = 2;
      ans[2] = (ans[0] - i - 1);
      if (ans[2] <= 0) {
        ans[2] += n;
      }
      ans[1] = ans[0] + 1;
      mini = diff;
    }
    i++;
    minang = orminang * (i + 1);
  }
  for (int j = 0; j < 3; j++) {
    cout << ans[j] << " ";
  }
  cout << endl;
  return 0;
}
