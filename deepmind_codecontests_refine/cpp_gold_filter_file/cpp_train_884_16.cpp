#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long a, b, c;
  cin >> a >> b >> c;
  if (a <= b - c || b > n) {
    cout << n / a << endl;
  } else {
    long long q, r;
    q = (n - b) / (b - c);
    r = (n - b) % (b - c);
    q++;
    q += (c + r) / a;
    cout << q << endl;
  }
  return 0;
}
