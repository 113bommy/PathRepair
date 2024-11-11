#include <bits/stdc++.h>
using namespace std;
const long long N = 100001;
int main() {
  long long k, n, s, p;
  cin >> k >> n >> s >> p;
  long long hojas = n / s + (k % s != 0 ? 1 : 0);
  long long tot = hojas * k;
  cout << tot / p + (tot % p != 0 ? 1 : 0) << endl;
  return 0;
}
