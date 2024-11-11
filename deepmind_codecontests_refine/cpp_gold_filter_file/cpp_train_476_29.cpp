#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, a, b, c, d;
  cin >> s >> a >> b >> c >> d;
  int m = (s * a) + (2 * c);
  int g = (s * b) + (2 * d);
  if (m < g) cout << "First";
  if (m == g) cout << "Friendship";
  if (m > g) cout << "Second";
}
