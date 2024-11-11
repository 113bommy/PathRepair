#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = s.length();
    if (n <= 10) {
      cout << s << endl;
    } else {
      cout << s.at(0);
      cout << n - 2;
      cout << s.at(n - 1);
    }
  }
}
