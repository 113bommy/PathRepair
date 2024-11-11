#include <bits/stdc++.h>
using namespace std;
int check(string s, string t) {
  int j = 0;
  for (int i = 0; i < s.size(); i++)
    if (s[i] != t[i]) j++;
  return j;
}
int main() {
  int q;
  cin >> q;
  while (q--) {
    int n, k;
    string s, t = "RGB";
    cin >> n >> k >> s;
    while (s.size() > t.size()) t += t;
    int min1 = 200000, j = 0;
    while (j < 3) {
      string K = t.substr(j, k);
      for (int i = 0; i <= n - k; i++) {
        string f = s.substr(i, k);
        min1 = min(min1, check(f, K));
      }
      j++;
    }
    cout << min1 << endl;
  }
  return 0;
}
