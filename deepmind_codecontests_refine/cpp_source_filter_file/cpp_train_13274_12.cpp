#include <bits/stdc++.h>
using namespace std;
vector<string> v;
vector<string> tmp;
string neg(string s) {
  int i;
  for (i = 0; i < s.size(); ++i) s[i] = (s[i] == '+' ? '-' : '+');
  return s;
}
int main() {
  int n, i, j;
  cin >> n;
  v.push_back("+");
  for (i = 1; i <= n; ++i) {
    tmp = v;
    v.clear();
    for (j = 0; j < tmp.size(); ++j) {
      v.push_back(tmp[j] + tmp[j]);
      v.push_back(tmp[j] + neg(tmp[j]));
    }
  }
  for (i = 0; i < v.size(); ++i) cout << v[i] << endl;
  return 0;
}
