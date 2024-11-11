#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, k;
  cin >> n >> k;
  long long int c, d;
  if (n / (2 * (k + 1)) < 1) {
    c = 0, d = 0;
    cout << d << " " << c << " " << n;
  } else {
    d = n / (2 * (k + 1));
    c = k * d;
    long long int s = c + d;
    cout << d << " " << c << " " << n - s;
  }
}
