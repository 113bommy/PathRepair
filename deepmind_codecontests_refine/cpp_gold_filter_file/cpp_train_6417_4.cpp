#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e3 + 4;
long long int ds(long long int n) {
  long long int ans = 0;
  while (n) {
    ans += (n % 10);
    n /= 10;
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n = 0, i, k;
  cin >> k;
  for (int i = 19; i < 2 * 10000000 + 1; i++) {
    long long int d = ds(i);
    if (d == 10) {
      n++;
      if (n == k) {
        cout << i;
        return 0;
      }
    }
  }
  return 0;
}
