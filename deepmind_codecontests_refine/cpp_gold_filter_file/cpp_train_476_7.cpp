#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2, i1, i2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  i1 = s * v1 + 2 * t1;
  i2 = s * v2 + 2 * t2;
  if (i1 < i2)
    cout << "First";
  else if (i1 > i2)
    cout << "Second";
  else
    cout << "Friendship";
}
