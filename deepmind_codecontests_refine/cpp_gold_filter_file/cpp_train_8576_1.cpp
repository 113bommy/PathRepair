#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  long long n;
  cin >> n;
  long long d1 = n % 10;
  long long d2 = n % 100 / 10;
  long long x = n / 10;
  long long y = n / 100 * 10 + d1;
  cout << max({x, y, n});
}
