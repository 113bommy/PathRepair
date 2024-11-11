#include <bits/stdc++.h>
using namespace std;
int a[100000], n, m, idx, x, y, d, z, u;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z >> u;
    idx += (u - x + 1) * (z - y + 1);
  }
  cout << idx << endl;
}
