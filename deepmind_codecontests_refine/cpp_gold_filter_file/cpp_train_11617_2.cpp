#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int z[n + 1];
  memset(z, 0, sizeof z);
  int f = n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int y;
    cin >> y;
    v.push_back(y);
  }
  for (int i = 0; i < n; i++) {
    if (f == v[i]) {
      z[v[i]] = 2;
      f--;
      cout << v[i];
      while (z[f] == 1) {
        cout << " " << f;
        z[f] = 2;
        f--;
      }
      cout << endl;
    } else {
      cout << endl;
      z[v[i]] = 1;
    }
  }
  return 0;
}
