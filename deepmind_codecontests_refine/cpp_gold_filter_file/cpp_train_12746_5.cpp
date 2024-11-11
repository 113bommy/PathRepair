#include <bits/stdc++.h>
using namespace std;
bool s[] = {1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
            0, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0};
int main() {
  string str;
  cin >> str;
  for (int x = 0; x < str.length() / 2; x++) {
    if (str[x] != str[str.length() - 1 - x]) {
      cout << "NO" << endl;
      return 0;
    }
  }
  for (int x = 0; x < str.length(); x++) {
    if (!s[str[x] - 'A']) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
