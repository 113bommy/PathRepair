#include <bits/stdc++.h>
using namespace std;
int main() {
  int x;
  cin >> x;
  string s;
  vector<string> ss;
  for (int i = 0; i < x; i++) {
    cin >> s;
    ss.push_back(s);
  }
  for (auto a : ss) {
    if (a.size() > 10)
      cout << a.at(0) << (a.size() - 2) << a.at((a.size() - 1)) << endl;
    else
      cout << a << endl;
  }
}
