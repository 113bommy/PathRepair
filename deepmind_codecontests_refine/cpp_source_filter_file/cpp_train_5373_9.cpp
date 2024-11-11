#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int z = s.size();
  int n;
  cin >> n;
  if (n > z)
    cout << "impossible";
  else {
    set<char> c;
    for (int i = 0; i < n; i++) {
      c.insert(s[i]);
    }
    if (c.size() >= n)
      cout << 0;
    else {
      cout << n - c.size();
    }
  }
}
