#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s1, s2;
  set<string> s;
  for (int i = 0; i < n; i++) {
    cin >> s1 >> s2;
    s.insert(s1 + s2);
  }
  cout << s.size();
  return 0;
}
