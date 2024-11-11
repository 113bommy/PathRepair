#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  getline(cin, str);
  auto n = str.length();
  for (size_t i = 0; i < n;) {
    auto j = i;
    while (j < n && isalpha(str[j])) j++;
    cout << str.substr(i, j - i);
    while (j < n && str[j] == ' ') j++;
    if (j < n &&
        (str[j] == ',' || str[j] == '.' || str[j] == '!' || str[j] == '?')) {
      cout << ',';
      j++;
    }
    while (j < n && str[j] == ' ') j++;
    if (j != n) cout << ' ';
    i = j;
  }
}
