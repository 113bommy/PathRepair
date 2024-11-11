#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a;
  cin >> a;
  if (a % 2 == 0)
    cout << a / 2 << endl;
  else {
    for (long long i = 3; i * i <= a; i++) {
      if (a % i == 0) {
        cout << (a - i) / 2 + 1 << endl;
        return 0;
      }
    }
    cout << 1 << endl;
  }
  return 0;
}
