#include <bits/stdc++.h>
using namespace std;
int n, k;
string s;
int main() {
  cin >> n >> k >> s;
  for (auto &c : s)
    if (c != s[k - 1]) c = '*';
  cout << s << endl;
  return 0;
}
