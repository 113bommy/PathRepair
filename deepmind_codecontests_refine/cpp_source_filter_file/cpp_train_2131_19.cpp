#include <bits/stdc++.h>
using namespace std;
long long fun(long long n) {
  if (n == 8) {
    return 1;
  }
  if (n == 0) {
    return 0;
  }
  if (n < 0) {
    return fun(-1 * n);
  }
  long long x = n % 10;
  if (x == 8) {
    return 1;
  }
  return fun(n / 10);
}
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  long long n;
  cin >> n;
  long long c = 0;
  long long a = n, b = n;
  while (fun(a) == 0) {
    a++;
    c++;
  }
  cout << c << endl;
}
