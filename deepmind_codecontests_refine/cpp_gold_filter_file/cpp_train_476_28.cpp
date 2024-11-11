#include <bits/stdc++.h>
using namespace std;
int main() {
  int t = 1;
  while (t--) {
    int s, v1, v2, t1, t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    if (2 * t1 + v1 * s == 2 * t2 + v2 * s) {
      cout << "Friendship" << endl;
    } else if (2 * t1 + v1 * s < 2 * t2 + v2 * s)
      cout << "First" << endl;
    else
      cout << "Second" << endl;
  }
  return 0;
}
