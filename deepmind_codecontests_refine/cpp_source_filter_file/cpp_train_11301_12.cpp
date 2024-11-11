#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int a, b, c, d, e;
  cin >> a >> b >> c >> d >> e;
  if (c > b || a > d) {
    cout << 0;
    return 0;
  } else {
    if (e >= max(a, c) && e <= min(b, d)) {
      cout << min(b, d) - max(a, c);
    } else {
      cout << min(b, d) - max(a, c) + a;
    }
  }
  return 0;
}
