#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long int n;
  cin >> n;
  long long int val = 1;
  long long int mod = 1000000007;
  for (long long int i = 0; i < 3 * n; i++) {
    val *= 3;
    val %= mod;
  }
  long long int vol = 1;
  for (long long int i = 0; i < n; i++) {
    vol *= 7;
    vol %= mod;
  }
  val -= vol;
  if (val > 0)
    cout << val;
  else
    cout << mod - val;
  return 0;
}
