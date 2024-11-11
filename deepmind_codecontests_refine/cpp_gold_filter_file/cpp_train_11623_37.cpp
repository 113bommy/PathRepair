#include <bits/stdc++.h>
using namespace std;
int main() {
  int v1, v2, v3, v4;
  cin >> v1 >> v2 >> v3 >> v4;
  if (v3 * 2 < v4 || v3 > 2 * v4 || v4 >= v2) {
    cout << "-1" << endl;
    return 0;
  }
  cout << v1 * 2 << endl;
  cout << v2 * 2 << endl;
  cout << max(v3, v4) << endl;
}
