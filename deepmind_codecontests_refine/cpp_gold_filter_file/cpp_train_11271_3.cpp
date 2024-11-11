#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, n;
  string s;
  cin >> t;
  while (t--) {
    string snew = "";
    cin >> n;
    cin >> s;
    cout << string(n, s[n - 1]) << endl;
  }
}
