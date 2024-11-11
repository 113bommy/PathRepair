#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
int main() {
  long long int n, m, p;
  long long int a, b, x, y;
  cin >> n >> a >> b;
  x = 0;
  y = n;
  while (n - a * x > 0) {
    if ((n - a * x) % b == 0) {
      cout << "YES\n" << x << " " << (n - a * x) / b << endl;
      return 0;
    }
    x++;
  }
  cout << "NO" << endl;
}
