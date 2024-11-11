#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, k, s;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> k;
    if (k % 2 == 0)
      s = (a * ((k / 2))) - (b * ((k / 2)));
    else
      s = (a * ((k / 2) + 1)) - (b * (k / 2));
    cout << s << endl;
  }
  return 0;
}
