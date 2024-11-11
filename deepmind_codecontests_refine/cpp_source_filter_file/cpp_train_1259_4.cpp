#include <bits/stdc++.h>
using namespace std;
bool check(char x, char y) {
  int dif = abs((int)x - (int)y);
  return ((dif == 0 || dif == 2));
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    bool ch = true;
    for (int i = 0; i < (n / 2); i++) {
      ch &= check(s[i], s[n - i - 1]);
    }
    if (ch)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
