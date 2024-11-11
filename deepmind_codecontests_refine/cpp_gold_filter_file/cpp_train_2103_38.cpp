#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    double a, b, c, d, k;
    cin >> a >> b >> c >> d >> k;
    int aa = ceil(a / c);
    int bb = ceil(b / d);
    if (aa + bb > k)
      cout << "-1" << endl;
    else
      cout << aa << " " << k - aa << endl;
  }
  return 0;
}
