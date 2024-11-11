#include <bits/stdc++.h>
using namespace std;
long long s, x;
long long car[2];
int main() {
  cin >> s >> x;
  car[0] = 1LL;
  for (int i = 0; i < 64; ++i) {
    long long k = x & (1LL << i), v = s & (1LL << i);
    if (k) {
      long long cr = (v) ? 0 : car[1] * 2;
      long long nocr = (v) ? car[0] * 2 : 0;
      car[0] = nocr;
      car[1] = cr;
    } else {
      long long cr = (v) ? car[1] : car[0];
      long long nocr = (v) ? car[1] : car[0];
      car[0] = nocr;
      car[1] = cr;
    }
  }
  cout << car[0] - ((s == x) ? 2LL : 0) << endl;
  return 0;
}
