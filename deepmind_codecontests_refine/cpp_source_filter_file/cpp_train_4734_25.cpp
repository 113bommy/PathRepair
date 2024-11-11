#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  string s;
  getline(cin, s);
  for (int i = s.size() - 1; i >= 0; --i) {
    char c = tolower(s[i]);
    while (isalpha(c)) {
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y')
        cout << "YES" << endl;
      else
        cout << "NO" << endl;
      break;
    }
  }
  return 0;
}
