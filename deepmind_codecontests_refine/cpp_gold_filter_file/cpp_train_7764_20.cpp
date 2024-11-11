#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
long long maxi;
long long andar(char op, long long n) {
  int p;
  for (p = 0; (1LL << p) <= n; p++) {
    if (((1LL << p) & n) != 0) {
      break;
    }
  }
  if (op == 'U') {
    if ((1LL << p) == (maxi / 2LL + 1LL)) return n;
    n -= (1LL << p);
    if ((n & (1LL << (p + 1))) == 0) {
      n += (1LL << (p + 1));
    }
    return n;
  } else if (op == 'L') {
    if (p == 0) return n;
    return (n - (1LL << p) + (1LL << (p - 1)));
  } else {
    if (p == 0) return n;
    return n + (1LL << (p - 1));
  }
}
int main() {
  int q;
  cin >> maxi >> q;
  string s;
  long long ini;
  for (int i = 0; i < q; i++) {
    cin >> ini >> s;
    for (int j = 0; j < s.size(); j++) {
      ini = andar(s[j], ini);
    }
    printf("%lld\n", ini);
  }
}
