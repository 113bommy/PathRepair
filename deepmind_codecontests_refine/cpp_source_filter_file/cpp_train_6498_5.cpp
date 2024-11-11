#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, ss;
  cin >> s;
  int l = s.length(), last = 0, sum = 0, after, before;
  if (s.find("bear") != string::npos) {
    for (int i = 0; i < l; i++) {
      if (i + 4 <= l) {
        ss = s.substr(i, 4);
        if (ss == "bear") {
          if ((i + 3) <= l) {
            after = ((l - 1) - (i + 2));
            before = (i - last) + 1;
            if (i != 0)
              if (after == 0) sum += before;
            if (before == 0) sum += after;
            sum += before * after;
          }
          last = i + 1;
        }
      }
    }
    cout << sum << endl;
  }
  return 0;
}
