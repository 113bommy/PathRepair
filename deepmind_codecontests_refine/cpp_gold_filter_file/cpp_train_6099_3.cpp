#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int l1 = s1.length();
  int l2 = s2.length();
  int a[l1];
  for (int i = 0; i < l1; ++i) {
    int x;
    cin >> x;
    a[x - 1] = i;
  }
  int j = 0;
  int l = 0;
  int r = l1;
  while (r - l > 1) {
    int m = (l + r) / 2;
    j = 0;
    for (int i = 0; i < l1; ++i) {
      if (j < l2) {
        if (m <= a[i] && s1[i] == s2[j]) ++j;
      }
    }
    if (j == l2) {
      if (l == m) break;
      l = m;
    } else {
      r = m;
    }
  }
  cout << l;
  return 0;
}
