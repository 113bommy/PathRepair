#include <bits/stdc++.h>
using namespace std;
long long n, k;
int t;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long res = 0;
    while (n > 0) {
      if (n % k == 0) {
        n = n / k;
        res++;
      } else {
        res += n % k;
        n -= n % k;
      }
    }
    cout << res << endl;
  }
}
