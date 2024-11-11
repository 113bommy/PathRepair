#include <bits/stdc++.h>
using namespace std;
long long n, x, q, t;
long long a, b, c;
long long bs(long long x, long long y) {
  long long b = (x - y) % 2;
  return min(b + ((x - y) / 2), c + 1);
}
int main() {
  cin >> n;
  while (n--) {
    long long ans = 0;
    cin >> a >> b >> c;
    if (c == 0) {
      if (a <= b)
        cout << 0 << endl;
      else
        cout << 1 << endl;
      continue;
    }
    if (a + c <= b) {
      cout << 0 << endl;
      continue;
    }
    cout << bs(a + c, b) << endl;
  }
}
