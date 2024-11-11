#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  cin >> n >> m;
  vector<int> kek;
  vector<int> f;
  int lel = 0;
  while (n--) {
    vector<char> v(m);
    for (int i = 0; i < m; i++) {
      cin >> v[i];
      if (v[i] == '*') {
        kek.push_back(i);
        f.push_back(lel);
      }
    }
    lel++;
  }
  if (f[1] == f[2]) {
    cout << f[0] + 1 << " ";
    if (kek[0] == kek[2]) {
      cout << kek[1] + 1;
    } else {
      cout << kek[2] + 1;
    }
  } else {
    cout << f[2] + 1 << " ";
    if (kek[0] == kek[2]) {
      cout << kek[0] + 1;
    } else {
      cout << kek[1] + 1;
    }
  }
  return 0;
}
