#include <bits/stdc++.h>
using namespace std;
int main() {
  int q = 0;
  cin >> q;
  for (int k = 0; k < q; ++k) {
    string a = "";
    string b = "";
    cin >> a >> b;
    bool f = 1;
    for (int i = 0; i < a.size(); ++i) {
      if (b.find(a[i]) != string::npos) {
        cout << "yes" << endl;
        f = 0;
        break;
      }
    }
    if (f) cout << "no" << endl;
  }
  return 0;
}
