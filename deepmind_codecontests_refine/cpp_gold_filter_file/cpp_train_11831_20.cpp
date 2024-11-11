#include <bits/stdc++.h>
using namespace std;
set<char> q = {'a', 'o', 'u', 'i', 'e'};
int main() {
  string s;
  cin >> s;
  int res = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= '0' && s[i] <= '9') {
      if ((s[i] - '0') % 2 == 1) res++;
    } else {
      if (q.count(s[i])) {
        res++;
      }
    }
  }
  cout << res;
  return 0;
}
