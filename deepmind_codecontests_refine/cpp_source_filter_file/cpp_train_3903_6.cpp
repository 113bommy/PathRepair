#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  if (x == 0) return 0;
  int z = 1;
  for (int g = 1; g <= x; g++) z = z * 2;
  return z;
}
int main() {
  string a;
  cin >> a;
  int m = a.size() - 1;
  int n = 0, v = 1;
  for (int g = 1; g <= m; g++) n += f(g);
  for (int g = 1; g < a.size(); g++) {
    if (a[g] == '7') {
      v += f(m - g);
      if (m - g == 0) v++;
    }
  }
  cout << v + n;
}
