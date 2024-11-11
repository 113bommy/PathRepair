#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cout << setprecision(25);
  long long n, a, b, c, d, i, j, k;
  a = 0;
  cin >> n;
  b = 1;
  n--;
  while (b <= n) {
    a++;
    b *= 2;
  }
  cout << a;
  return 0;
}
