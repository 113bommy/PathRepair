#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, k, now, p;
  cin >> q >> k;
  string vowels[4], line;
  int scheme = 0;
  bool possible = true;
  for (int i = 0; i < q; i++) {
    now = 0;
    for (int j = 0; j < 4; j++) {
      cin >> line;
      vowels[j] = "";
      for (p = line.length() - 1; p >= 0 && vowels[j].length() < k; p--) {
        char v = line[p];
        if (v == 'a' || v == 'e' || v == 'i' || v == 'o' || v == 'u')
          vowels[j] += v;
      }
      if (vowels[j].length() < k) {
        possible = false;
        break;
      }
      vowels[j] = line.substr(p + 1);
    }
    if (vowels[0] == vowels[1] && vowels[2] == vowels[3]) {
      if (vowels[0] == vowels[2])
        now = 0;
      else
        now = 1;
    } else if (vowels[0] == vowels[2] && vowels[1] == vowels[3]) {
      now = 2;
    } else if (vowels[0] == vowels[3] && vowels[1] == vowels[2]) {
      now = 3;
    } else
      possible = false;
    if (scheme == 0 || scheme == now)
      scheme = now;
    else if (now)
      possible = false;
  }
  string op;
  if (!possible)
    op = "NO";
  else
    switch (scheme) {
      case 0:
        op = "aaaa";
        break;
      case 1:
        op = "aabb";
        break;
      case 2:
        op = "abab";
        break;
      case 3:
        op = "abba";
        break;
    }
  cout << op << endl;
  return 0;
}
