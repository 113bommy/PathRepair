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
  set<char> vis;
  for (int i = 1; i <= a; i++) vis.insert(s[int(s.size()) - i]);
  for (int i = 0, c = 0; i < 26 && c < a; i++) {
    if (vis.count('a' + i)) continue;
    s += 'a' + i;
    c++;
  }
  for (int i = 0; i < b; i++) s += s.back();
  string s2 = "";
  int ml = l % (2 * (a + b));
  while (r-- >= l) {
    s2 += s[ml++];
    if (ml >= 2 * (a + b)) ml = 0;
  }
  set<char> anw;
  int h = l % (a + b);
  if (h >= a && a > b) {
    for (int i = 0; i < a + b - h; i++) s2[i] -= b;
  }
  for (char t : s2) anw.insert(t);
  cout << int(anw.size()) << endl;
}
