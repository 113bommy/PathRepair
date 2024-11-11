#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0, n, t = 0, cnt = 1, maxm = 0;
  n = s.size();
  while (t < 2) {
    if ((s[i] == 'b' && s[(i + 1) % n] == 'w') ||
        (s[i] == 'w' && s[(i + 1) % n] == 'b')) {
      while ((s[i] == 'b' && s[(i + 1) % n] == 'w') ||
             (s[i] == 'w' && s[(i + 1) % n] == 'b')) {
        cnt++;
        if (cnt > n) break;
        i++;
        if (i > n - 1) t++, i = i % n;
      }
      if (cnt > n)
        maxm = n;
      else
        maxm = max(maxm, cnt);
      cnt = 1;
    } else {
      i++;
      if (i > n - 1) t++, i = i % n;
    }
  }
  cout << maxm;
  return 0;
}
