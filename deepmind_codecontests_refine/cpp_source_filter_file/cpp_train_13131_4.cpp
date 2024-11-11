#include <bits/stdc++.h>
using namespace std;
void compareFunction(string s1, string s2) {
  int x = s1.compare(s2);
  if (x == 0) cout << 0 << endl;
  if (x > 0)
    cout << 1 << endl;
  else
    cout << -1 << endl;
}
int main() {
  string s;
  string j;
  cin >> s >> j;
  transform(s.begin(), s.end(), s.begin(), ::tolower);
  transform(j.begin(), j.end(), j.begin(), ::tolower);
  compareFunction(s, j);
  return 0;
}
