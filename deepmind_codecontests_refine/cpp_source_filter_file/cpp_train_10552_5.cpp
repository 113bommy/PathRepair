#include <bits/stdc++.h>
using namespace std;
set<string> s;
int ans = 0;
int main() {
  string a;
  cin >> a;
  int l = a.length();
  for (int i = 0; i < l - 1; i++) {
    string b;
    for (int j = i; j < l; j++) {
      b += a[j];
      if (s.find(b) != s.end()) ans = max(ans, (int)b.length());
      s.insert(b);
    }
  }
  cout << ans;
}
