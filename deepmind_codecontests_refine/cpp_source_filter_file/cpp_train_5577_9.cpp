#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c;
  cin >> n;
  cin >> a;
  cin >> b;
  cin >> c;
  if ((n % 4) == 0) {
    cout << "0" << endl;
  } else if (((n + 1) % 4) == 0) {
    cout << min(a, min(2 * b, b + c)) << endl;
  } else if (((n + 2) % 4) == 0) {
    cout << min(b, min(2 * a, c + a)) << endl;
  } else if (((n + 3) % 4) == 0) {
    cout << min(c, min(3 * a, b + a)) << endl;
  }
  return 0;
}
