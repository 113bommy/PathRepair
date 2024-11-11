#include <bits/stdc++.h>
using namespace std;
long long wynik(long long h, long long n, bool lewo) {
  if (h == 0) return 0;
  long long srod = 1LL << (h - 1);
  if (n <= srod)
    return 1 + (lewo ? 0 : 2 * srod - 1) + wynik(h - 1, n, false);
  else
    return 1 + (lewo ? 2 * srod - 1 : 0) + wynik(h - 1, n - srod, true);
}
void zrob_test() {
  long long h, n;
  cin >> h >> n;
  cout << wynik(h, n, true) << '\n';
}
int main() {
  ios_base::sync_with_stdio(0);
  zrob_test();
  return 0;
}
