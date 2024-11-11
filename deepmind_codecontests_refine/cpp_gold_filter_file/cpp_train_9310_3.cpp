#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << s[0];
  bool a = 0;
  int n = s.size();
  for (int i = int(1); i < int(s.size()); i++) {
    bool p = 0;
    if (i < n - 2 && !a) {
      if (s[i] == 'a' && s[i + 1] == 't') cout << '@', p = 1, a = 1, i++;
    }
    if (i < n - 3) {
      if (s[i] == 'd' && s[i + 1] == 'o' && s[i + 2] == 't')
        cout << '.', p = 1, i += 2;
    }
    if (!p) cout << s[i];
  }
  cout << endl;
}
