#include <bits/stdc++.h>
using std::vector;
using namespace std;
int main() {
  string s;
  cin >> s;
  int a = 0, b = 0, c = 0, flag = 0;
  for (int i = 1; i < s.size() - 1; i++) {
    if ((s[i] == 'A' && s[i + 1] == 'B' && s[i - 1] == 'C') ||
        (s[i] == 'A' && s[i + 1] == 'C' && s[i - 1] == 'B')) {
      cout << "YES";
      flag = 1;
      break;
    } else if ((s[i] == 'B' && s[i + 1] == 'A' && s[i - 1] == 'C') ||
               (s[i] == 'B' && s[i + 1] == 'C' && s[i - 1] == 'A')) {
      cout << "YES";
      flag = 1;
      break;
    } else if ((s[i] == 'C' && s[i + 1] == 'B' && s[i - 1] == 'A') ||
               (s[i] == 'c' && s[i + 1] == 'A' && s[i - 1] == 'B')) {
      cout << "YES";
      flag = 1;
      break;
    }
  }
  if (!flag) cout << "NO";
}
