#include <bits/stdc++.h>
using namespace std;
long int n, m, s;
int main() {
  cin >> n >> m;
  while (n > 0 && m > 0) {
    if (n >= m) {
      s = s + n / m;
      n = n % m;
    } else {
      s = s + m / n;
      m = m % n;
    }
  }
  cout << s << endl;
}
