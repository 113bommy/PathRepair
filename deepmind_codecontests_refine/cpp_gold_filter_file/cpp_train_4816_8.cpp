#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n;
  cin >> t;
  while (t--) {
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '(') {
        a++;
      } else {
        a--;
      }
      b = min(a, b);
    }
    cout << abs(b) << endl;
  }
  return 0;
}
