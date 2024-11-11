#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main() {
  double s = 0, n, b, p = 1.5, k = 0;
  cin >> n;
  s += n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    if (b == p) {
      k++;
    } else {
      if (k > 1) {
        s += (k / 2) * (k - 1);
      }
      p = b;
      k = 1;
    }
  }
  if (k > 1) {
    s += (k / 2) * (k - 1);
  }
  cout << setprecision(0) << s << endl;
  return 0;
}
