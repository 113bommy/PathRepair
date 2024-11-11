#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long p, q, a, t;
  cin >> p >> q >> n;
  for (int i = 0; i < n; i++) {
    cin >> a;
    if (q == 0 || (a != p / q && a != p / q - 1)) {
      cout << "NO";
      return 0;
    } else {
      p -= q * a;
      swap(p, q);
    }
  }
  if (q == 0)
    cout << "YES";
  else
    cout << "NO";
}
