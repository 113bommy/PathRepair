#include <bits/stdc++.h>
using namespace std;
long long modulo = 1000000007;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n;
  int k;
  cin >> n >> k;
  long long rem;
  long long lol;
  int ans;
  long long number;
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    long long rem = n % x;
    if (i == 0) {
      lol = rem;
      ans = i + 1;
      number = n / x;
    } else {
      if (rem < lol) {
        lol = rem;
        ans = i + 1;
        number = n / x;
      }
    }
  }
  cout << ans << " " << number << endl;
  return 0;
}
