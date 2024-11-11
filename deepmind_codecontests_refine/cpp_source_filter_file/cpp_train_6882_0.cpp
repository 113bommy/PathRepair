#include <bits/stdc++.h>
using namespace std;
long long dignum, ans, wek;
int main() {
  long long n, m;
  cin >> n;
  if (n == 1) {
    cout << 1;
    return 0;
  }
  m = n;
  while (n > 0) {
    dignum++;
    n /= 10;
  }
  dignum--;
  ans += 9 * dignum;
  long long wek = 1;
  while (dignum > 1) {
    wek *= 10;
    wek += 1;
    dignum--;
  }
  m -= 9 * wek;
  while (m > 0) {
    ans += m % 10;
    m /= 10;
  }
  cout << ans << endl;
}
