#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  string a, b;
  cin >> n;
  cin >> a >> b;
  long long a1 = 0, a0 = 0, c0 = 0, c1 = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == '1')
      a1++;
    else
      a0++;
  }
  for (int i = 0; i < n; i++) {
    if (a[i] == '0' && b[i] == '0') {
      c0++;
    } else if (a[i] == '1' && b[i] == '0') {
      c1++;
    }
  }
  int d = (a1 * c0);
  cout << d + (c1 * (a0 - c0)) << endl;
}
