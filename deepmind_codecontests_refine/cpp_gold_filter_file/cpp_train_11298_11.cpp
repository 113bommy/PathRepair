#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, n, j;
  cin >> n;
  string a, b, c;
  multimap<int, string> m;
  for (i = 0; i < n; i++) {
    cin >> a >> b;
    if (b == "rat") {
      m.insert({1, a});
    }
    if (b == "woman") {
      m.insert({2, a});
    }
    if (b == "child") {
      m.insert({2, a});
    }
    if (b == "man") {
      m.insert({3, a});
    }
    if (b == "captain") {
      m.insert({4, a});
    }
  }
  for (auto it : m) {
    cout << it.second << endl;
  }
  return 0;
}
