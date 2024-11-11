#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, t, a, b, c, x, n;
  map<char, int> m;
  int s;
  for (i = 0; i < 4; i++) {
    cin >> s;
    m[s]++;
  }
  cout << m.size() << endl;
  return 0;
}
