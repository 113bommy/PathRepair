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
    for (int i = 0; i < 2 * n; i += 2) cout << s[i];
    cout << "\n";
  }
}
