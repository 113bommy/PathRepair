#include <bits/stdc++.h>
using namespace std;
int main() {
  string c;
  long long a, b, d, e, w, x, y, z, s, i, n, link = 0, pearl = 0;
  cin >> c;
  for (i = 0; i <= c.size() - 1; i++) {
    if (c[i] == '-') {
      link++;
    }
    if (c[i] == 'o') {
      pearl++;
    }
  }
  if (pearl == 0) {
    cout << "YES";
    return 0;
  }
  if (link % pearl == 0) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
