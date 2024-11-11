#include <bits/stdc++.h>
using namespace std;
int dist(char a, char b) {
  if (a < b) swap(a, b);
  return min(b - a, 26 - (b - a));
}
int main() {
  string s;
  cin >> s;
  char cp;
  int poz, tot = 0;
  cp = 'a';
  poz = 0;
  while (poz < s.size()) {
    tot += dist(cp, s[poz]);
    cp = s[poz];
    poz++;
  }
  cout << tot;
}
