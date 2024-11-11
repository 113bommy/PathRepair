#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  bool isHaicu = true;
  for (int i = 0; i < 3; ++i) {
    int k = 0;
    getline(cin, s);
    for (int j = 0; j < (int)s.size(); ++j) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' ||
          s[j] == 'u')
        ++k;
    }
    if (i == 0 || i == 2)
      isHaicu = k == 5;
    else
      isHaicu = k == 7;
    if (!isHaicu) break;
  }
  cout << isHaicu ? "YES" : "NO";
}
