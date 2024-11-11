#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  string s;
  vector<char> c;
  cin >> n;
  cin >> s;
  while (n) {
    if (n % 2) {
      c.push_back(s[0]);
    } else {
      c.insert(c.begin(), s[0]);
    }
    s.erase(0, 1);
    n = s.size();
  }
  for (int i = 0; i < n; i++) {
    cout << c[i];
  }
  return 0;
}
