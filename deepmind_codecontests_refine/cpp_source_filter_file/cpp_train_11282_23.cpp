#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  getline(cin, s);
  getline(cin, t);
  int count = 0;
  for (int i = 0; i < t.length(); ++i) {
    if (s[i] == t[count]) ++count;
  }
  cout << count + 1;
}
