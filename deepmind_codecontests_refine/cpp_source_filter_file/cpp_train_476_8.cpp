#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2, x1, x2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  x1 = s * v1 + (t1 * 2);
  x2 = s * v2 + (t2 * 2);
  if (x1 > x2)
    cout << "First" << endl;
  else if (x1 < x2)
    cout << "Second" << endl;
  else
    cout << "Friendship" << endl;
  return 0;
}
