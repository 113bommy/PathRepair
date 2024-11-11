#include <bits/stdc++.h>
using namespace std;
const long long int mo = 998244353;
int main() {
  long long int n, s = 0, po[19], k, de;
  po[0] = 1;
  for (int e = 1; e < 19; e++) po[e] = (po[e - 1] * 10) % mo;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> k;
    de = 0;
    while (k) {
      s += (n * (po[2 * de] + po[2 * de + 1]) * (k % 10)) % mo;
      k /= 10;
      de++;
    }
  }
  cout << s % mo;
}
