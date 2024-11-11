#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t, s, x, div;
  cin >> t >> s >> x;
  if (t == x)
    cout << "YES" << endl;
  else if (t < x && s > x)
    cout << "NO" << endl;
  else if (t > x)
    cout << "NO" << endl;
  else if (x >= s + t) {
    div = (x - t) / s;
    if ((div * s) + t == x || (div * s) + t + 1 == x)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else
    cout << "NO" << endl;
  return 0;
}
