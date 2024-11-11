#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, h;
  int i = 0;
  cin >> s >> h;
  for (i = 0; i < s.size(); i++) {
    s[i] = tolower(s[i]);
  }
  for (i = 0; i < h.size(); i++) {
    h[i] = tolower(h[i]);
  }
  if (s > h)
    cout << 1;
  else if (s < h)
    cout << -1;
  else
    cout << 0;
  return 0;
}
