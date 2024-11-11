#include <bits/stdc++.h>
using namespace std;
int main() {
  long long a, b, c, d, e, f, g, h, i, j;
  map<long long, long long> mp;
  cin >> a >> b >> c;
  long long z[a];
  e = 0;
  for (i = 0; i < a; i++) {
    cin >> z[i];
    d = z[i] % c;
    mp[d]++;
    if (mp[d] > e) {
      e = mp[d];
      h = d;
    }
  }
  j = 0;
  if (e >= b) {
    cout << "Yes" << endl;
    for (i = 0; i < a; i++) {
      if (z[i] % c == h) {
        cout << z[i] << " ";
        j++;
      }
      if (j == b) break;
    }
    cout << endl;
  } else
    cout << "No" << endl;
  return 0;
}
