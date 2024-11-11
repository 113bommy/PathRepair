#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int count = 0;
  while (s.size() != 0) {
    int i;
    int si = s.size();
    for (i = 0; i < si; i++) {
      if (s[i] == s[i + 1]) {
        s.erase(i, i + 1);
        count++;
        break;
      }
    }
    if (i == si) {
      break;
    }
  }
  if (count % 2 == 1) {
    cout << "Yes\n";
  } else
    cout << "No\n";
  return 0;
}
