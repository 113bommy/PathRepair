#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, p, q, i;
  while (cin >> n >> m) {
    if (n > 30) n = 30;
    p = 1;
    for (i = 1; i <= n; i++) {
      p = p * 2;
    }
    cout << m % p << endl;
  }
  return 0;
}
