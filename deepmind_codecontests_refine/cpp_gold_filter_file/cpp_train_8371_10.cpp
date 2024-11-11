#include <bits/stdc++.h>
using namespace std;
int main() {
  int answ = 0, count = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == s[i + 1]) {
      count++;
    } else if (count % 2 != 0) {
      answ++;
      count = 0;
    }
  }
  cout << answ << endl;
  return 0;
}
