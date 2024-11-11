#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  set<string> s;
  while (n--) {
    string t;
    cin >> t;
    s.insert(t);
  }
  cout << s.size() << endl;
}
