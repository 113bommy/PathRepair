#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    long long int a = floor(pow(n, 0.5));
    long long int b = ceil(pow(n, 0.5));
    long long int c = a * a;
    long long int d = b * b;
    long long int diff = (d - c) / 2;
    if (a == b) {
      cout << 1 << " " << a << endl;
      continue;
    }
    long long int chk = ceil(double((c + d)) / 2);
    if (chk == n) {
      cout << b << " " << b << endl;
    } else if (n < chk) {
      cout << (n - c) << " " << b << endl;
    } else {
      cout << b << " " << (d - n + 1) << endl;
    }
  }
}
