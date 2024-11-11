#include <bits/stdc++.h>
using namespace std;
int main() {
  int s, v1, v2, t1, t2;
  cin >> s >> v1 >> v2 >> t1 >> t2;
  if (v1 * s + 2 * t1 > v2 * s + 2 * t2) {
    cout << "First" << endl;
  } else if (v1 * s + 2 * t1 < v2 * s + 2 * t2) {
    cout << "Second" << endl;
  } else {
    cout << "Friendship" << endl;
  }
  getchar();
  return 0;
}
