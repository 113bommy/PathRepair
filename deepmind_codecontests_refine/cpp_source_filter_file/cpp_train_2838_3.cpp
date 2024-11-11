#include <bits/stdc++.h>
using namespace std;
int x, y, z, t;
vector<int> a(3);
int main() {
  cin >> t;
  for (int gg = 0; gg < t; gg++) {
    for (auto& it : a) {
      cin >> it;
    }
    sort(a.begin(), a.end());
    if (a[1] != a[2]) {
      cout << "NO";
    } else {
      cout << "YES" << '\n';
      cout << a[0] << ' ' << a[0] << ' ' << a[2] << '\n';
    }
  }
}
