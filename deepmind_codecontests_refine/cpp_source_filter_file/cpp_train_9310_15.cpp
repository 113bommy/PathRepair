#include <bits/stdc++.h>
using namespace std;
int main() {
  string second;
  bool ok = 0;
  cin >> second;
  for (int i = 1; i < second.length() - 2; i++) {
    if (second.substr(i, 3) == "dot" && i < second.length() - 4)
      second = second.substr(0, i) + "." +
               second.substr(i + 3, second.length() - i - 3);
    if (second.substr(i, 2) == "at" && !ok)
      second =
          second.substr(0, i) + "@" + second.substr(i + 2, second.length() - 2),
      ok = 1;
  }
  cout << second;
  return 0;
}
