#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
  long long T;
  cin >> T;
  while (T--) {
    long long n, sum = 1;
    cin >> n;
    for (int i = 1; i < 2 * n; i++) {
      sum = (sum * i) % mod;
    }
    cout << (sum * n) % mod << endl;
  }
}
