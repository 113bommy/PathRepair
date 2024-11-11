#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  srand(time(NULL));
  ;
  int T = 1;
  cin >> T;
  while (T--) {
    int n, r = 0, c = 0;
    string s;
    cin >> n >> s;
    for (int i = 0; i < int(n); i++) r += s[i] == 'R';
    if (r > 0 && r < n) {
      int j = 0;
      while (s[(j - 1 + n) % n] == 'R' || s[j] == 'L') j++;
      s = s.substr(j, n - j) + s.substr(0, j);
      char d = 'R';
      for (int i = 0; i < int(n); i++) {
        int k = i;
        while (k < n && s[k] == d) k++;
        c += (k - i) / 3;
        d = (d == 'R') ? 'L' : 'R';
        i = k - 1;
      }
      cout << c << endl;
    } else
      cout << (n + 2) / 3 << endl;
  }
  return 0;
}
