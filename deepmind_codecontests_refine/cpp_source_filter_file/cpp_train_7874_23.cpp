#include <bits/stdc++.h>
using namespace std;
int main() {
  set<string> s;
  s.insert("don't think so");
  s.insert("not bad");
  s.insert("cool");
  s.insert("don't touch me");
  s.insert("great!");
  for (int i = 0; i < 6; i++) {
    string st;
    cout << i << '\n';
    cout.flush();
    getline(cin, st);
    if (st == "no") continue;
    if (s.find(st) != s.end())
      cout << "normal\n";
    else
      cout << "grumpy\n";
    cout.flush();
    return 0;
  }
  return 0;
}
