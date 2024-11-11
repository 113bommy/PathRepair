#include <bits/stdc++.h>
using namespace std;
int niz[1000];
int main() {
  int n, m;
  string s;
  cin >> n >> m;
  cin >> s;
  for (int i = 0; i < n; i++) {
    niz[(char)s[i] - 97]++;
  }
  for (int i = 0; i < 26; i++) {
    if (niz[i] > m) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
