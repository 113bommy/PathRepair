#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b;
  cin >> a >> b;
  if (b - a <= 1 || (b - a == 2 && b % 2 == 1))
    cout << -1 << endl;
  else {
    long long b = 0;
    if (a % 2 == 1) b++;
    cout << a + b << " " << a + 1 + b << " " << a + 2 + b << endl;
  }
}
