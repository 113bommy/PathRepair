#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const long long mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(false);
  cout.tie(NULL);
  cin.tie(NULL);
  ;
  long long n, k;
  cin >> n >> k;
  map<long long, long long> m;
  for (long long i = 0; i < n; i++) {
    long long x;
    cin >> x;
    m[i % k] += x;
  }
  long long mn = 0x3f3f3f3f3f3f3f3fLL, idx = 0;
  for (long long i = 0; i < k; i++) {
    if (m[i] < mn) {
      idx = i + 1;
      mn = m[i];
    }
  }
  cout << idx << "\n";
  return 0;
}
