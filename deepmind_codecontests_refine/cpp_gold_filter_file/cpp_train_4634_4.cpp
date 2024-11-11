#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0;
  string a, b = "hello", c = "";
  cin >> a;
  for (auto x : b)
    for (i = j; i < a.length(); i++) {
      if (a[i] == x) {
        c += a[i];
        j = i + 1;
        break;
      }
    }
  if (c == "hello")
    cout << "YES";
  else
    cout << "NO";
}
