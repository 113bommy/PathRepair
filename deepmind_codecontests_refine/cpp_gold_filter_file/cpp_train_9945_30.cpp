#include <bits/stdc++.h>
using namespace std;
string s[2];
string read() {
  cin >> s[0];
  cin >> s[1];
  reverse(s[1].begin(), s[1].end());
  string p = s[0] + s[1];
  p.erase(p.find('X'), 1);
  return p;
}
int main() {
  string p1 = read();
  string p2 = read();
  p1 += p1;
  if (p1.find(p2) != string::npos) {
    puts("YES");
  } else
    puts("NO");
  return 0;
}
