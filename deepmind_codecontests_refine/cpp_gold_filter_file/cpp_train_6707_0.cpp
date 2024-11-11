#include <bits/stdc++.h>
using namespace std;
int main() {
  string t;
  cin >> t;
  long long a = 0, b = 0, c = 0, d = 0, q;
  for (long long i = 0; i < t.size(); i++) {
    if (t[i] == 'n') {
      a++;
    } else if (t[i] == 'i') {
      b++;
    } else if (t[i] == 'e') {
      c++;
    } else if (t[i] == 't') {
      d++;
    }
  }
  if (a < 5) {
    q = (a / 3);
  } else {
    q = ((a - 1) / 2);
  }
  long long ans = 10000000;
  ans = min(ans, q);
  ans = min(ans, (c / 3));
  ans = min(ans, b);
  ans = min(ans, d);
  cout << ans;
  return 0;
}
