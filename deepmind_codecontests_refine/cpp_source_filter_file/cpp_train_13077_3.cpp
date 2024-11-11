#include <bits/stdc++.h>
using namespace std;
long long a, b;
int main() {
  cin >> a >> b;
  if (b - a >= 5)
    cout << "0";
  else {
    long long res = 1;
    for (int i = b; i != a; --i) {
      res = (res * (i % 10)) % 10;
    }
    cout << res;
  }
  return 0;
}
