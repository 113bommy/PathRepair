#include <bits/stdc++.h>
using namespace std;
long long tpp = 1e18;
int tp = 1e9;
long long p, d;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> p >> d;
  ;
  long long res = p + 1;
  for (long long i = 10; i <= tpp; i *= 10)
    if (p % i <= d) res = p - p % i;
  cout << res - 1 << endl;
  ;
  return 0;
  ;
}
