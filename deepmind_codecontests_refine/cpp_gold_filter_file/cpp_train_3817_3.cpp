#include <bits/stdc++.h>
using namespace std;
string s;
int n, x;
int main() {
  cin >> n >> s;
  if (s == "0") return cout << 0, 0;
  for (auto c : s)
    if (c == '0') x++;
  cout << 1;
  while (x--) cout << 0;
}
