#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int i1, j1, i2, j2;
  i1 = 7 - (s1[1] - '1');
  j1 = s1[0] - 'a';
  i2 = 7 - (s2[1] - '1');
  j2 = s2[0] - 'a';
  vector<string> v;
  while (i1 != i2 or j1 != j2) {
    string s = "";
    if (j1 < j2) {
      j1++;
      s += "R";
    } else if (j1 > j2) {
      j1--;
      s += "U";
    }
    if (i1 < i2) {
      i1++;
      s += "D";
    } else if (i1 > i2) {
      i1--;
      s += "U";
    }
    v.push_back(s);
  }
  cout << int(v.size()) << endl;
  for (int i = 0; i < int(v.size()); i++) {
    cout << v[i] << endl;
  }
}
