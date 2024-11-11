#include <bits/stdc++.h>
using namespace std;
int main() {
  int z = 1, t, s, q, k;
  cin >> t >> s >> q;
  while (s * q < t) {
    s += s * q;
    z++;
  };
  cout << z << endl;
  return 0;
}
