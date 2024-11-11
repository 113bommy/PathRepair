#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  string s, t;
  set<string> v;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s >> t;
    v.insert(s + '%' + t);
  }
  cout << v.size() << endl;
  return 0;
}
