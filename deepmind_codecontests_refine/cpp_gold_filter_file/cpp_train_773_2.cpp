#include <bits/stdc++.h>
using namespace std;
int n, p;
string s;
int main() {
  while (cin >> n >> p) {
    cin >> s;
    int len = s.size();
    bool flg = false;
    int i;
    for (i = len - 1; i >= 0; --i) {
      s[i]++;
      if (s[i] >= 'a' + p) continue;
      while ((i - 1 >= 0 && s[i - 1] == s[i]) ||
             (i - 2 >= 0 && s[i - 2] == s[i])) {
        s[i]++;
        if (s[i] >= 'a' + p) {
          break;
        }
      }
      if (s[i] < 'a' + p) break;
    }
    if (i == -1) {
      cout << "NO" << endl;
      continue;
    }
    for (int j = i + 1; j < len; ++j) {
      int t = 'a';
      while ((j - 1 >= 0 && t == s[j - 1]) || (j - 2 >= 0 && t == s[j - 2])) {
        t++;
      }
      if (t >= 'a' + p) {
        s = "NO";
        break;
      }
      s[j] = t;
    }
    cout << s << endl;
  }
  return 0;
}
