#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a1, t1, a2, t2, n1 = 0, n2 = 0;
  cin >> n >> a1 >> a2 >> t1 >> t2;
  n1 += t1 * 2;
  n2 *= t2 * 2;
  n1 += a1 * n;
  n2 += a2 * n;
  if (n1 > n2) cout << "Second";
  if (n2 > n1) cout << "First";
  if (n1 == n2) cout << "Friendship";
}
