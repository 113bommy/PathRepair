#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d;
long long x[10000006], y[1000006];
int main() {
  cin >> a;
  for (int i = 1; i <= a; i++) {
    cin >> x[i];
    y[i] = x[i];
  }
  sort(x + 1, x + a + 1);
  sort(y + 1, y + a + 1);
  reverse(y + 1, y + a + 1);
  for (int i = 1; i <= a; i++) {
    c += x[i] * y[i];
  }
  cout << c % 10007;
}
