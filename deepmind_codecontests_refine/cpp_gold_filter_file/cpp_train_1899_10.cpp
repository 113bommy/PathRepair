#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int d, n;
    cin >> d >> n;
    long long last_pow2 = 1;
    long long last_poss = 1;
    while ((last_pow2 << 1) + 1 < d) {
      last_poss = last_poss * (last_pow2 + 2) + (last_pow2 + 1);
      last_poss %= n;
      last_pow2 <<= 1;
      last_pow2 += 1;
    }
    last_poss = last_poss * (d - last_pow2 + 1) + (d - last_pow2);
    last_poss %= n;
    cout << last_poss << endl;
  }
}
