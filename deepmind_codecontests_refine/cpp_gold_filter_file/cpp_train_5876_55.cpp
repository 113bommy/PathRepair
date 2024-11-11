#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string v;
  cin >> v;
  int k = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == v[v.size() - 1 - i]) {
      k++;
    }
  }
  if (k == s.size()) {
    cout << "YES";
  } else {
    cout << "NO";
  }
  return 0;
}
