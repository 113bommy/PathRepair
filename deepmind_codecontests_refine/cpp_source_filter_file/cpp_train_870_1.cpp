#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, m, a, b, l, r;
  vector<int> wires;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> t;
    wires.push_back(t);
  }
  cin >> m;
  while (m--) {
    cin >> a >> b;
    r = wires[a - 1] - b;
    l = wires[a - 1] - r - 1;
    wires[a - 1] = 0;
    if (a > 0) {
      wires[a - 2] += l;
    }
    if (a < n - 1) {
      wires[a] += r;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << wires[i] << "\n";
  }
  return 0;
}
