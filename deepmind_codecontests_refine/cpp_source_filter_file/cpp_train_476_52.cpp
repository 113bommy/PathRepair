#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  t1 = 2 * t1 + s * v1;
  t2 = 2 * t2 + s * v2;
  if (t1 > t2)
    cout << "First\n";
  else if (t1 < t2)
    cout << "Second\n";
  else
    cout << "Friendship\n";
  return 0;
}
