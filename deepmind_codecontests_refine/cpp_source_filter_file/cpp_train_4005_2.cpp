#include <bits/stdc++.h>
using namespace std;
int n;
unsigned long long a, b;
string s;
int nrb(unsigned long long n) {
  int r = 0;
  for (; n; ++r, n &= (n - 1))
    ;
  return r;
}
int main() {
  for (cin >> n; n--;) {
    cin >> a >> b;
    int bmax = nrb(b);
    unsigned long long r = b;
    if (nrb(a) >= bmax) {
      bmax = nrb(a);
      r = a;
    }
    for (int i = 62; i >= 0; --i)
      if (b & (1LL << i)) {
        unsigned long long aux = b ^ (1 << i);
        aux |= ((1LL << i) - 1LL);
        if (aux >= a && nrb(aux) > bmax) {
          bmax = nrb(aux);
          r = aux;
        } else if (aux >= a && nrb(aux) == bmax)
          r = min(r, aux);
      }
    cout << r << '\n';
  }
}
