#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j;
  cin >> n;
  string s[102];
  for (i = 0; i < n; i++) {
    cin >> s[i];
    for (j = 0; j < i; j++) {
      if (s[j] == s[i]) break;
    }
    if (j == i)
      cout << "NO \n";
    else
      cout << "YES \n";
  }
  return 0;
}
