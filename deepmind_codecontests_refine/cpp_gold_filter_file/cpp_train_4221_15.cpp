#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
void solve() {
  stringstream ss;
  int n;
  cin >> n;
  ss << oct << n;
  string s;
  ss >> s;
  int ctr = 0;
  for (int i = 0; i < s.size(); i++) ctr += s[i] == '1';
  cout << ctr;
}
int main() {
  srand(1313);
  solve();
  return 0;
}
