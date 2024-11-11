#include <bits/stdc++.h>
using namespace std;
string alph = {"abcdefghijklmnopqrstuvwxyz"};
int main() {
  string s;
  cin >> s;
  cout << 26 * (s.size() + 1) - s.size();
  return 0;
}
