#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string p = "";
    for (int k = 0; k < 2 * n - 1; k = k + 2) {
      p = p + s[k];
    }
    cout << p << endl;
  }
  return 0;
}
