#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, l, r;
  cin >> a >> b >> l >> r;
  l--, r--;
  if (r - l > 100) {
    cout << 2 * a - min(b, a - 1);
    return 0;
  }
  string s = "";
  for (int i = 0; i < a; i++) s += i + 'a';
  for (int i = 0; i < b; i++) s += s[a - 1];
  for (int i = 0; i < min(a - 1, b); i++) s += i + 'a';
  for (int i = 0; i < a - min(a - 1, b); i++) s += i + a + 'a';
  for (int i = 0; i < b; i++) s += s[2 * a + b - 1];
  string s2 = "";
  int ml = l % (2 * (a + b));
  while (r-- >= l) {
    s2 += s[ml++];
    if (ml >= 2 * (a + b)) ml = 0;
  }
  set<char> anw;
  int h = l % (a + b);
  if (h >= a && a > b) {
    for (int i = 0; i < a + b - h; i++) s2[i] -= a - b - 1;
  }
  for (char t : s2) anw.insert(t);
  cout << int(anw.size()) << endl;
}
