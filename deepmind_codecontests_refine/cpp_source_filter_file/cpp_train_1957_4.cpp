#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  for (auto& c : s) c = (c - 'a' + n) % 26 + 'A';
  cout << s << '\n';
  return 0;
}
