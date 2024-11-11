#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, j, pearl = 0, link = 0, n;
  cin >> s;
  n = s.length();
  for (i = 0; i < n; i++) {
    if (s[i] == '-') {
      link++;
    } else {
      pearl++;
    }
  }
  if (pearl == 0) {
    cout << "NO" << endl;
    return 0;
  }
  if (link == 0 || pearl == 1 || link % pearl == 0) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}
