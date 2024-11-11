#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  int a, b;
  a = s * v1 + 2 * t1;
  b = s * v2 + 2 * t2;
  if (a < b) {
    cout << "First" << endl;
  }
  if (a > b) {
    cout << "Second" << endl;
  }
  if (a == b) {
    cout << "Friendship" << endl;
  }
  return 0;
}
