#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i += 2)
    for (int j = 0; j < s.size() - 1; j += 2) {
      if (s[i] <= s[j + 2]) {
        swap(s[i], s[j + 2]);
      }
    }
  if (s.size() > 1) {
    for (int i = 2; i < s.size(); i++) cout << s[i];
    cout << s[1] << s[0] << endl;
  } else
    cout << s << endl;
  return 0;
}
