#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t, fl, idx;
  string s;
  cin >> n >> t;
  cin >> s;
  idx = s.size() - 1, fl = 0;
  for (int i = int(0); i <= int(s.size() - 1); i++) {
    if (s[i] == '.') {
      fl = 1;
      continue;
    }
    if (fl && s[i] >= '5') {
      idx = i;
      break;
    }
  }
  int mrk = s.size() - 1;
  fl = 0;
  while (t-- && s[idx] >= '5') {
    if (s[idx - 1] == '.') {
      fl = 2;
      if (s[idx - 2] == '9')
        s[idx - 2] = '0';
      else
        s[idx - 2]++;
      int j = idx - 2;
      mrk = idx - 2;
      while (s[j] == '0') {
        if (!j) {
          fl = 1;
          break;
        } else
          s[j - 1] = (s[j] == '9' ? '0' : s[j - 1] + 1);
        --j;
      }
      break;
    }
    s[idx - 1]++;
    idx--;
    mrk = idx;
  }
  if (fl == 1) cout << 1;
  for (int i = int(0); i <= int(mrk); i++) cout << s[i];
  return 0;
}
