#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, ne = 0, r;
  string s;
  string p = "RGB";
  cin >> n >> s;
  for (int i = 0; i < n; i++) {
    r = i;
    while (r < n - 1 && s[r + 1] == s[i]) r++;
    if (r != i) {
      for (int j = i + 1; j <= r; j += 2) {
        char c = s[j];
        if (j != r)
          c = p[(p.find(s[j]) + 1) % 3], ne++, s[j] = c;
        else {
          for (int k = 0; k < 3; k++) {
            if (p[k] != c && p[k] != s[j + 1]) c = p[k];
          }
          ne++;
          s[j] = c;
        }
      }
    }
  }
  cout << ne << endl;
  cout << s << endl;
}
