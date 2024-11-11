#include <bits/stdc++.h>
using namespace std;
int main() {
  setlocale(LC_ALL, "TURKISH");
  long long int r, c;
  cin >> r >> c;
  vector<long long int> v;
  for (long long int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for (long long int a = 0; a < c; a++) {
      if (s[a] == '*') {
        v.push_back(i + 1);
        v.push_back(a + 1);
      }
    }
  }
  if (v[0] == v[2]) {
    cout << v[4] << " ";
    (v[1] == v[5]) ? cout << v[3] : cout << v[1];
  } else {
    cout << v[0] << " ";
    (v[1] == v[5]) ? cout << v[3] : cout << v[1];
  }
  return 0;
}
