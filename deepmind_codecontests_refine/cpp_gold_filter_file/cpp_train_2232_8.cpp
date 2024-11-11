#include <bits/stdc++.h>
using namespace std;
int main() {
  int q, w, e, r;
  cin >> q >> w >> e >> r;
  string s;
  cin >> s;
  unsigned long long int c = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '1') {
      c += q;
    }
    if (s[i] == '2') {
      c += w;
    }
    if (s[i] == '3') {
      c += e;
    }
    if (s[i] == '4') {
      c += r;
    }
  }
  cout << c << endl;
  return 0;
}
