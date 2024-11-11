#include <bits/stdc++.h>
using namespace std;
long double pi = 3.14159265358979323;
const double EPS = 1e-12;
const int N = 1e6 + 5;
const int mod = 998244353;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  if (n > k * (k - 1)) return cout << "NO", 0;
  cout << "YES"
       << "\n";
  long long l = 0;
  for (int i = 1; i < k; i++) {
    for (int j = i + 1; j <= k; j++) {
      if (l < n) {
        cout << i << " " << j << "\n";
        l++;
      } else
        break;
      if (l < n) {
        cout << j << " " << i << "\n";
        l++;
      } else
        break;
    }
    if (l >= n) break;
  }
  return 0;
}
