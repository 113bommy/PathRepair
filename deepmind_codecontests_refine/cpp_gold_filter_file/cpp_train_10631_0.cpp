#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4;
long long arr[mod];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }
  cout << n + 1 << "\n";
  long long prideta = 0;
  for (int i = 0; i < n; ++i) {
    long long dbr = (arr[n - i - 1] + prideta) % mod;
    cout << "1 " << n - i << " ";
    long long reik = mod + mod - i - 1;
    cout << reik - dbr << "\n";
    prideta += (reik - dbr);
    prideta %= mod;
  }
  cout << "2 " << n << " " << mod;
  return 0;
}
