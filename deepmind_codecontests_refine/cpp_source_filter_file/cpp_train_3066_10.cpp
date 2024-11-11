#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, t;
  set<string> sp;
  cin >> n;
  for (; n; --n) {
    cin >> s >> t;
    sp.insert(s + t);
  }
  cout << sp.size();
  return 0;
}
