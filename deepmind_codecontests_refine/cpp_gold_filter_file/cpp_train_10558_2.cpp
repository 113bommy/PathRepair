#include <bits/stdc++.h>
using namespace std;
int main() {
  string temp, a, b;
  cin >> temp;
  int limit = temp.find('|');
  a = temp.substr(0, limit);
  b = temp.substr(limit + 1);
  cin >> temp;
  for (int i = 0; i < temp.size(); i++) {
    if (a.size() <= b.size()) {
      a.push_back(temp[i]);
    } else
      b.push_back(temp[i]);
  }
  if (a.size() == b.size()) {
    cout << a << '|' << b;
  } else
    cout << "Impossible";
}
