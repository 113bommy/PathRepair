#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int res = 1, aux = 0;
  vector<int> v;
  string s;
  cin >> s;
  s += "#";
  bool f = 0;
  for (int i = 0; i < s.size() - 1; i++) {
    if ((s[i] - '0') + (s[i + 1] - '0') == 9) {
      if (f) {
        aux++;
      } else {
        aux = 1;
        f = 1;
      }
    } else {
      aux++;
      if (f && aux % 2) {
        v.push_back((aux + 1) / 2);
      } else if (f)
        v.push_back(aux / 2);
      f = 0;
      aux = 0;
    }
  }
  if (v.size())
    for (int i = 0; i < v.size(); i++) res *= v[i];
  cout << res << endl;
}
