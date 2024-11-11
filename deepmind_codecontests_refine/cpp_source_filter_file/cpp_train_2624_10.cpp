#include <bits/stdc++.h>
using namespace std;
int sc1() {
  int x;
  scanf("%d", &x);
  return x;
}
long long sc2() {
  long long x;
  scanf("%lld", &x);
  return x;
}
int main() {
  long long n, m, t, div, mod, value;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    div = m / n;
    mod = m % n;
    value = div + 1;
    if (n > m) {
      cout << m * m << endl;
    } else if (mod == 0) {
      cout << (long long)(div * div) * n << endl;
    } else {
      cout << (long long)(((value * value) * mod) + ((n - mod) * (div * div)))
           << endl;
    }
  }
  return 0;
}
