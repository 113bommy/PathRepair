#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  set<string> s;
  string name;
  while (n--) {
    cin >> name;
    s.insert(name);
    if (s.size() == count) {
      count++;
      cout << "NO \n";
    } else {
      cout << "YES \n";
    }
  }
  return 0;
}
