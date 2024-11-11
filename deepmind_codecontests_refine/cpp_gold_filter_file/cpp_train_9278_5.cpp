#include <bits/stdc++.h>
using namespace std;
int main() {
  long long k;
  cin >> k;
  if (k < 4)
    cout << k + 1;
  else {
    int a = sqrt(k);
    if (a * a >= k)
      cout << 2 * a;
    else {
      int b = a;
      b++;
      if (b * a >= k)
        cout << b + a << endl;
      else {
        cout << 2 * b << endl;
      }
    }
  }
  return 0;
}
