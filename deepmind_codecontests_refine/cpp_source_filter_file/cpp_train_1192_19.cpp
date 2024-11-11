#include <bits/stdc++.h>
using namespace std;
int main() {
  string m;
  cin >> m;
  string s;
  cin >> s;
  int n = s.size();
  char a[34] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k',
                'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                'w', 'x', 'y', 'z', '[', ']', ';', ',', '.', '/'};
  char r[34] = {'s', 'n', 'v', 'f', 'r', 'g', 'h', 'j', 'o', 'k', 'l',
                ';', ',', 'm', 'p', '[', 'w', 't', 'd', 'y', 'i', 'b',
                'e', 'c', 'u', 'x', ']', '`', '`', '.', '/', '/'};
  char l[34] = {'`', 'v', 'x', 's', 'w', 'd', 'f', 'g', 'u', 'h', 'j',
                'k', 'n', 'b', 'i', 'o', '`', 'e', 'a', 'r', 'y', 'c',
                'q', 'z', 't', '`', 'p', '[', 'l', 'm', ',', '.'};
  if (m[0] == 'R') {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 34; j++) {
        if (s[i] == r[j]) cout << a[j];
      }
    }
  } else if (m[0] == 'L') {
    for (int i = 0; i < n; i++) {
      for (int k = 0; k < 34; k++) {
        if (s[i] == l[k]) cout << a[k];
      }
    }
  }
  return 0;
}
