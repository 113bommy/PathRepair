#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    vector<int> v(10050, 0);
    for (int i = 0; i < n; i++) {
      int te;
      cin >> te;
      v[te] = 1;
    }
    int k = 0, p = 1;
    while (x >= k) {
      if (v[p] == 1)
        p++;
      else
        k++, p++;
    }
    cout << p - 2 << endl;
  }
  return 0;
}
