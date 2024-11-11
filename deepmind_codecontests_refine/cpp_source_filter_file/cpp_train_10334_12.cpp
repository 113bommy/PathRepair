#include <bits/stdc++.h>
using namespace std;
bool vo(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}
string filter(string s, int k) {
  int pos = ((int)(s).size()), cnt = 0;
  while (pos > 0 && cnt < k) pos--, cnt += vo(s[pos]);
  if (cnt < k) return "-";
  return s.substr(pos);
}
int main() {
  int n, k;
  cin >> n >> k;
  int res = 15;
  for (register int i = (0); i < (int)(n); ++i) {
    string a[4];
    for (register int j = (0); j < (int)(4); ++j)
      cin >> a[j], a[j] = filter(a[j], k);
    int tmp = 0;
    if (a[0] == "-" || a[1] == "-" || a[2] == "-" || a[3] == "-") {
      res = 0;
      continue;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == a[3]) tmp |= 1;
    if (a[0] == a[1] && a[2] == a[3]) tmp |= 2;
    if (a[1] == a[3] && a[0] == a[2]) tmp |= 4;
    if (a[0] == a[3] && a[1] == a[2]) tmp |= 8;
    res &= tmp;
  }
  if (res == 0)
    cout << "NO"
         << "\n";
  else if (res & 1)
    cout << "aaaa"
         << "\n";
  else if (res & 2)
    cout << "aabb"
         << "\n";
  else if (res & 4)
    cout << "abab"
         << "\n";
  else if (res & 8)
    cout << "baab"
         << "\n";
  return 0;
}
