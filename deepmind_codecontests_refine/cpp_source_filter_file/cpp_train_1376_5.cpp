#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < s.size(); j++) {
      if (s[s.size() - 1] == 'o') {
        cout << "FILIPINO" << endl;
        break;
      } else if (s[s.size() - 1] == 'u') {
        cout << "JAPANESE" << endl;
        break;
      } else if (s[s.size() - 1] == 'a') {
        cout << "KOREAN";
        break;
      }
    }
  }
}
