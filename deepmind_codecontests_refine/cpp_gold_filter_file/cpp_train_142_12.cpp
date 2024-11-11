#include <bits/stdc++.h>
using namespace std;
string s;
char a;
int b, c, d, i, k, n;
int main() {
  cin >> s;
  k = s.size();
  if (k < 2) d = 1;
  while (n < 100 && d == 0) {
    while (i < k - 2 && d == 0) {
      if (s[i] > s[i + 2]) {
        a = s[i + 2];
        s[i + 2] = s[i];
        s[i] = a;
      }
      i += 2;
    }
    n++;
    i = 0;
  }
  cout << s;
}
