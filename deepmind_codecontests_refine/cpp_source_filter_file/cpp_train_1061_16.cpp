#include <bits/stdc++.h>
using namespace std;
int n, r, g;
int main() {
  cin >> n;
  if (n % 36 == 1) {
    cout << n / 36 + 1 << " " << 0;
    return 0;
  }
  r = n / 36;
  n = n % 36;
  g = n / 3;
  n = n % 3;
  if (n == 2) g++;
  cout << r << " " << g;
}
