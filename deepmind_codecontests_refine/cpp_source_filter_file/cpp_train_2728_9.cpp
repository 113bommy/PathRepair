#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  while (q--) {
    int num;
    cin >> num;
    vector<int> v;
    for (int i = 0; i < num; i++) {
      int a;
      cin >> a;
      v.push_back(a);
    }
    bool found = false;
    for (int i = 1; i <= num; i++) {
      if (abs(v[i] - v[i - 1]) >= 2) {
        cout << "YES" << endl;
        cout << i << " " << (i + 1) << endl;
        found = true;
        break;
      }
    }
    if (!found) cout << "NO" << endl;
  }
  return 0;
}
