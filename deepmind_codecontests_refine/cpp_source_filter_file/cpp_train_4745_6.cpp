#include <bits/stdc++.h>
using namespace std;
int n, l, r;
int gcd(int a, int b) { return (a == 0) ? b : gcd(b % a, a); }
int main() {
  cin >> n >> l >> r;
  if (n == 1)
    cout << r - l + 1;
  else if (n == 2)
    cout << (long long)(r - l + 1) * (r - l);
  else {
    n--;
    int res = 0;
    int dau = 1, cuoi = pow(r, 1.0 / n);
    for (int i = dau; i < cuoi; ++i)
      for (int j = i + 1; j <= cuoi; ++j)
        if (gcd(i, j) == 1 && r / pow(j, n) >= l / pow(i, n)) {
          res += (int(r / pow(j, n))) - (int(l / pow(i, n)));
          if (l == ((int(l / pow(i, n))) * pow(i, n))) res++;
        }
    cout << res * 2 << endl;
  }
}
