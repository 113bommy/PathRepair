#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string a, b, c;
    cin >> a >> b >> c;
    bool ok = false;
    int g = 0;
    for (int i = 0; i < a.size(); i++) {
      if (b[i] == c[i] || a[i] == c[i]) g++;
    }
    if (g == c.size())
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  }
}
