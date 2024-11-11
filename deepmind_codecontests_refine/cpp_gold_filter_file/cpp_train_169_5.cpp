#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string a;
  cin >> a;
  int mx = 0;
  char f = a[0], s = a[1];
  for (int j = 0; j < x - 2; j++) {
    int c = 0;
    char ma = a[j], mb = a[j + 1];
    for (int i = j + 1; i < x - 1; i++) {
      if (ma == a[i] && mb == a[i + 1]) c++;
    }
    if (mx < c) {
      mx = c;
      f = ma;
      s = mb;
    }
  }
  cout << f << s << endl;
  return 0;
}
