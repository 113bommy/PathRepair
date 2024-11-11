#include <bits/stdc++.h>
using namespace std;
int main() {
  string a, b, c;
  int ham = 0;
  bool first = true;
  cin >> a >> b;
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) != b.at(i)) ham++;
  }
  if (ham % 2) {
    cout << "impossible\n";
    return 0;
  }
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) == b.at(i)) {
      c.push_back('0');
    } else {
      if (first) {
        c.push_back(a.at(i));
        first = false;
      } else {
        c.push_back(b.at(i));
        first = true;
      }
    }
  }
  cout << c;
  return 0;
}
