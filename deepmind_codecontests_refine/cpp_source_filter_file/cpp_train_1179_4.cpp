#include <bits/stdc++.h>
using namespace std;
int main() {
  ifstream ff("file.txt");
  string s1, s2;
  ff >> s1 >> s2;
  reverse(s2.begin(), s2.end());
  while (s1.length() != s2.length()) {
    if (s1.length() > s2.length()) {
      s2.insert(s2.begin(), 1, '0');
    } else {
      s1.insert(s1.begin(), 1, '0');
    }
  }
  int x, y;
  istringstream iss(s2);
  iss >> x;
  istringstream iss1(s1);
  iss1 >> y;
  cout << x + y << endl;
  return 0;
}
