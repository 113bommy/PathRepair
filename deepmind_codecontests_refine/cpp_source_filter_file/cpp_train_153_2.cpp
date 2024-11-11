#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j, k = 0, n, w = 0;
  string s;
  while (getline(cin, s)) {
    if (s[0] == '+') {
      k++;
      continue;
    }
    if (s[0] == '-') {
      k--;
      continue;
    }
    n = s.find(':');
    j = s.size();
    w += (j - n - 2) * k;
  }
  cout << w;
}
