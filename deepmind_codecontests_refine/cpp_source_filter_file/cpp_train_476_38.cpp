#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  if (s * v1 + 2 * t1 > s * v2 + 2 * t2) cout << "first";
  if (s * v1 + 2 * t1 < s * v2 + 2 * t2) cout << "second";
  if (s * v1 + 2 * t1 == s * v2 + 2 * t2) cout << "friendship";
  return 0;
}
