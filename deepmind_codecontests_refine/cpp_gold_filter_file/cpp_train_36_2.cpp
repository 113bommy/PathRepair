#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, r = 0;
  char s[200000];
  cin >> n >> s;
  int a = 0, f = 0, i = 0;
  for (int j = 0; j < n; ++j) {
    if (s[j] == 'A')
      ++a;
    else if (s[j] == 'F')
      ++f;
    else if (s[j] == 'I')
      ++i;
  }
  if (i > 0) {
    cout << (i == 1 ? 1 : 0) << endl;
  } else {
    cout << (n - f) << endl;
  }
  return 0;
}
