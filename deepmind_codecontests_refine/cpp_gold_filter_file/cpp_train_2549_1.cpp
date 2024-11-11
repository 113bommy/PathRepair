#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  cout << (int)s.size() * 26 + 26 - (int)s.size() << endl;
  return 0;
}
