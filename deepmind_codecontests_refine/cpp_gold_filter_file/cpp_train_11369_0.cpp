#include <bits/stdc++.h>
using ll = long long;
using namespace std;
using pii = pair<int, int>;
int main() {
  string s;
  cin >> s;
  int count{-1};
  for (int i = 1; i < s.length(); i++) {
    if (int(s[i]) >= 97 && int(s[i]) <= 122 && s[i - 1] != '/') {
      count++;
      for (int i = 1; i <= (2 * count); i++) cout << " ";
      cout << s[i - 1] << s[i] << s[i + 1] << endl;
    } else if (s[i] == '/') {
      for (int i = 1; i <= (2 * count); i++) cout << " ";
      cout << s[i - 1] << s[i] << s[i + 1] << s[i + 2] << endl;
      count--;
    }
  }
  return 0;
}
