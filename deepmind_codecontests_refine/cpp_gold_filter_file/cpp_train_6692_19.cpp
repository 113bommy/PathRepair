#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  int n;
  int s = 0;
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> n;
    s = s + ((n % 10 - 1) * 10);
    int q = 0;
    while (n > 0) {
      n = n / 10;
      q++;
    }
    if (q == 4) s = s + 10;
    if (q == 3) s = s + 6;
    if (q == 2) s = s + 3;
    if (q == 1) s = s + 1;
    cout << s << endl;
    s = 0;
  }
  return 0;
}
