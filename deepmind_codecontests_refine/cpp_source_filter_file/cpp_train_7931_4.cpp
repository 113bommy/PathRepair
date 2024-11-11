#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, n, i, x;
  cin >> q;
  while (q--) {
    int t = 0;
    cin >> n;
    vector<int> v;
    for (i = 0; i < n; i++) {
      cin >> x;
      v.push_back(x);
    }
    sort(v.begin(), v.end());
    if (n != 1) {
      for (i = 0; i < v.size(); i++) {
        if (v[i + 1] - v[i] > 1) {
          continue;
        } else {
          t++;
          break;
        }
      }
    }
    if (t == 0)
      cout << 1 << endl;
    else
      cout << 2 << endl;
  }
}
