#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a % b == 0)
    cout << 0 << endl;
  else {
    int mod = a % b;
    cout << min(mod * d, (b - mod) * c);
  }
}
