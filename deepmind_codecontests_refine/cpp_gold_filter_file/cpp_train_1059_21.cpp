#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t;
  cin >> t;
  while (t--) {
    int n, a = 0;
    cin >> n;
    string s;
    while (1) {
      a++;
      string x = to_string(a);
      s += x;
      if (n > s.length())
        n -= s.length();
      else {
        cout << s[n - 1] << endl;
        break;
      }
    }
  }
  return 0;
}
