#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, k = 0, n, m;
  string s1, s2;
  getline(cin, s1);
  getline(cin, s2);
  n = s1.length();
  m = s2.length();
  for (i = 0; i < n - m + 1; i++) {
    if (s2 == s1.substr(i, m)) {
      k++;
      i = i + m;
    }
  }
  cout << k;
}
