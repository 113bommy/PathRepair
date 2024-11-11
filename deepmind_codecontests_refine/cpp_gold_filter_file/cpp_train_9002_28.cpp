#include <bits/stdc++.h>
using namespace std;
int a[100000], n, m, idx, x, y, d, z, u;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x >> y >> z >> u;
    idx += abs(u - y + 1) * abs(z - x + 1);
  }
  cout << idx << endl;
}
