#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2, m, n;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  m = t1 * 2 + s * v1;
  n = t2 * 2 + s * v2;
  if (m == n) cout << "Friendship";
  if (m < n) cout << "First";
  if (m > n) cout << "Second";
}
