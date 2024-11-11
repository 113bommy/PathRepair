#include <bits/stdc++.h>
using namespace std;
string s;
int x;
int main() {
  cin >> s;
  if (s == "0") return cout << 0, 0;
  for (auto c : s)
    if (c == '0') x++;
  cout << 1;
  while (x--) cout << 0;
}
