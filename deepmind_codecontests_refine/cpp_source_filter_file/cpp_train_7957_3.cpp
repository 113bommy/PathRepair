#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s;
  cin >> s;
  cin >> n;
  int a[26], m = INT_MIN, j;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] > m) {
      m = a[i];
      j = i + 97;
    }
  }
  char c = j;
  int su = 0;
  s.insert(s.size(), n, c);
  for (int i = 0; s[i]; i++) {
    su += (i + 1) * a[s[i] - 97];
  }
  cout << su;
}
