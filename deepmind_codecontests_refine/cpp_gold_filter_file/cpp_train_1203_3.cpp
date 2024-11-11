#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, k, l = 0, c = 0, p = 0, t = 0, f;
  string s;
  cin >> s;
  k = s.length();
  for (i = 0; i < k; i++) {
    if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' ||
        s[i] == 'U' || s[i] == 'Y') {
      l = i + 1;
      t = max(t, l - p);
      p = l;
      c = 1;
    }
  }
  if ((k - p) >= t) t = k - p + 1;
  if (c == 1)
    t = t;
  else
    t = k + 1;
  cout << t << endl;
}
