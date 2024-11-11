#include <bits/stdc++.h>
using namespace std;
int main() {
  long long s = 1, t1 = 1, t2 = 1, t3 = 1;
  int x, y, z, k, M;
  cin >> x >> y >> z >> k;
  for (int i = 0; i < k; i++) {
    if (t1 == x && t2 == y && t3 == z) break;
    if (t1 < x && (t1 <= t2 || t2 == x) && (t1 <= t3 || t3 == x)) {
      s += t2 * t3;
      t1++;
      continue;
    }
    if (t2 < y && (t2 <= t1 || t1 == x) && (t2 <= t3 || t3 == x)) {
      s += t1 * t3;
      t2++;
      continue;
    }
    if (t3 < z && (t3 <= t1 || t1 == x) && (t3 <= t2 || t2 == x)) {
      s += t1 * t2;
      t3++;
    }
  }
  cout << s << endl;
  return 0;
}
