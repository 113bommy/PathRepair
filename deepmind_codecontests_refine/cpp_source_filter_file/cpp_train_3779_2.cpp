#include <bits/stdc++.h>
using namespace std;
int main() {
  int af = 0, as = 0;
  string a, b;
  cin >> a >> b;
  int l = a.length();
  for (int i = 0; i < l; i++) {
    a[i] = a[i] - '0';
    if (a[i] == 4)
      af++;
    else
      as++;
    b[i] = b[i] - '0';
  }
  int f = 0, s = 0, cnt = 0;
  for (int i = 0; i < l; i++) {
    if (a[i] != b[i]) {
      if (b[i] == 4)
        f++;
      else
        s++;
    }
  }
  int one = min(af, as);
  int two = min(f, s);
  cnt += min(one, two);
  int x = f + s - 2 * cnt;
  cnt += x;
  cout << x << endl;
  return 0;
}
