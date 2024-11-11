#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
int main() {
  long long t;
  cin >> t;
  for (long long i9 = 0; i9 < t; i9++) {
    long long x, y, k;
    cin >> x >> y >> k;
    long long p = k * y + k;
    p--;
    cout << p / (x - 1) + (p % (x - 1) != 0) << endl;
  }
}
