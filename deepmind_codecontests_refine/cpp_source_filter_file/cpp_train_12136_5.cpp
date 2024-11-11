#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  string s;
  cin >> a >> s;
  if (a > 2) {
    for (int i = a - 2; i >= 0; i -= 2) {
      cout << s[i];
    }
    if (a % 2 == 0)
      for (int i = 1; i < a; i += 2) {
        cout << s[i];
      }
    else
      for (int i = 0; i < a; i += 2) {
        cout << s[i];
      }
  }
  cout << s << endl;
  return 0;
}
