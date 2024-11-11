#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  long s, a, b, c;
  long long res;
  cin >> t;
  while (t != 0) {
    cin >> s >> a >> b >> c;
    res = s / c;
    res += (res / a) * b;
    cout << res << endl;
    t--;
  }
  return 0;
}
