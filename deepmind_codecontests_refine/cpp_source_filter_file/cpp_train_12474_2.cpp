#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int w;
  cin >> s >> w;
  for (int i = 0; i < (int)s.size(); i += 3) {
    cout << s[i];
  }
  cout << endl;
  return 0;
}
