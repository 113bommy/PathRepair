#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long long n, k, a;
  for (cin >> t; t; t--) {
    int cnt = 0;
    cin >> n >> k;
    while (n) {
      cnt += n % k;
      n -= n % k;
      n /= k;
      cnt++;
    }
    cout << cnt - 1 << endl;
  }
  return 0;
}
