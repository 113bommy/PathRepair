#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int n;
  cin >> s;
  s += 'b';
  n = s.size();
  for (int i = 0; i < n - 1; i++) {
    if (s[i] != s[i + 1])
      cout << 1 << " ";
    else
      cout << 0 << " ";
  }
}
