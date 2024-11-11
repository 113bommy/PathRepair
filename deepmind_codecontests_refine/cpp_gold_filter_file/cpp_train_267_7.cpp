#include <bits/stdc++.h>
using namespace std;
int main() {
  int c, v0, v1, a, l;
  cin >> c >> v0 >> v1 >> a >> l;
  int p = 0, days = 0;
  while (true) {
    days++;
    p += v0;
    if (p >= c) {
      break;
    }
    v0 += a;
    if (v0 > v1) {
      v0 = v1;
    }
    p -= l;
  }
  cout << days << endl;
  return 0;
}
