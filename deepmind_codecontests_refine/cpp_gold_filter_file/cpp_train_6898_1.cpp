#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, i, j, c;
  cin >> t;
  while (t--) {
    string s;
    int m[101];
    cin >> s;
    x = s.size();
    j = 0;
    c = 0;
    for (i = 0; i < x; i++) {
      if (s[i] == '1')
        c++;
      else if (c > 0) {
        m[j++] = c;
        c = 0;
      }
    }
    if (c > 0) m[j++] = c;
    sort(m, m + j);
    c = 0;
    for (i = j - 1; i >= 0; i = i - 2) c = c + m[i];
    cout << c << endl;
  }
}
