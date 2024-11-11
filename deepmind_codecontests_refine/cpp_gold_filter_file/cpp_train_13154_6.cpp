#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  set<char> f(s.begin(), s.end());
  if (f.size() % 2 == 0)
    cout << "CHAT WITH HER!\n";
  else
    cout << "IGNORE HIM!\n";
  return 0;
}
