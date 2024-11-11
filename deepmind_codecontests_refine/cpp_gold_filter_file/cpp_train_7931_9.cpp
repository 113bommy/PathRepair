#include <bits/stdc++.h>
using namespace std;
int q;
int main() {
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n;
    cin >> n;
    vector<int> a;
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      a.push_back(x);
    }
    sort(a.begin(), a.end());
    bool neben = false;
    for (int i = 0; i < n - 1; i++) {
      if (a[i] + 1 == a[i + 1]) {
        neben = true;
      }
    }
    if (neben) {
      cout << 2 << endl;
    } else {
      cout << 1 << endl;
    }
  }
  return 0;
}
