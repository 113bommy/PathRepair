#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  set<char> se;
  if (k > s.length())
    cout << "impossible";
  else {
    for (int i = 0; i < s.length(); i++) se.insert(s[i]);
    k -= se.size();
    if (k)
      cout << k;
    else
      cout << "0";
  }
}
