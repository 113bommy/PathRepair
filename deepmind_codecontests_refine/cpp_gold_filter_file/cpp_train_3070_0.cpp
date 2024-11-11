#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string a, b;
  cin >> a >> b;
  long long d = 0, c = d;
  for (long long i = 0; i < a.length(); i++) {
    if (a[i] == '1' && b[i] == '0')
      c++;
    else if (a[i] == '0' && b[i] == '1')
      d++;
  }
  if (c == d) {
    for (long long i = 0; i < a.length(); i++) cout << "0";
  } else if ((c + d) % 2 == 0) {
    if (c > d) {
      long long l = (c - d) / 2;
      for (long long i = 0; i < a.length(); i++) {
        if (a[i] == '1' && b[i] == '0' && l) {
          l--;
          cout << "1";
        } else
          cout << "0";
      }
    } else {
      long long l = (d - c) / 2;
      for (long long i = 0; i < a.length(); i++) {
        if (a[i] == '0' && b[i] == '1' && l) {
          l--;
          cout << "1";
        } else
          cout << "0";
      }
    }
  } else
    cout << "impossible";
  return 0;
}
