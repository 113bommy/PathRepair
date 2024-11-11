#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int n;
  for (int i = 0; i < 3; i++) {
    int t;
    cin >> t;
    v.push_back(t);
  }
  cin >> n;
  for (int i = 0; i <= 200; i++) {
    for (int j = i + 1; j <= 200; j++) {
      for (int k = j + 1; k <= 200; k++) {
        if (k < max(v[0], n) or j < max(v[1], n) or i < max(v[2], n)) continue;
        if (k > v[0] * 2 or j > v[1] * 2 or i > v[2] * 2) continue;
        if (k <= n * 2 or j <= n * 2) continue;
        if (i > n * 2) continue;
        cout << k << endl << j << endl << i;
        return 0;
      }
    }
  }
  cout << -1;
}
