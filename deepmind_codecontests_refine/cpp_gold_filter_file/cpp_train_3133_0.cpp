#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int i, j, res = 0, count = 0;
  for (i = s.size() - 1, j = t.size() - 1; i >= 0, j >= 0; i--, j--) {
    if (s[i] != t[j]) {
      res = i + 1 + j + 1;
      count = 1;
      break;
    }
  }
  if (count)
    cout << res;
  else if (i >= 0)
    cout << i + 1;
  else if (j >= 0)
    cout << j + 1;
  else
    cout << "0";
}
