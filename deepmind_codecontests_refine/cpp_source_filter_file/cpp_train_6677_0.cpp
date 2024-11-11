#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  int a, b, q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    cin >> n >> a >> b;
    if (a * 2 <= b)
      cout << n * a << endl;
    else {
      {
        if (n % 2 == 0)
          cout << b * n / 2 << endl;
        else
          cout << b * n / 2 + a << endl;
      }
    }
  }
  return 0;
}
