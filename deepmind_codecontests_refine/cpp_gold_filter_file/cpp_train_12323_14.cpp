#include <bits/stdc++.h>
using namespace std;
string s;
int n, a[1000], i, j, k, l, m, sum, w;
int main() {
  for (i = 0; i < 8; i++) {
    cin >> s;
    for (j = 0; j < s.size() - 1; j++)
      if (s[j] == s[j + 1]) {
        cout << "NO" << endl;
        return 0;
      }
  }
  cout << "YES" << endl;
  return 0;
}
