#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, i, st = -1, en = -1;
    string s;
    cin >> n;
    cin >> s;
    for (i = 0; i < s.size(); i++) {
      if (s[i] == '1') {
        if (st == -1) {
          st = i;
          en = i;
        } else
          en = i;
      }
    }
    if (st == -1 && en == -1)
      cout << n << endl;
    else
      cout << max(2 * en, 2 * (n - st)) << endl;
  }
  return 0;
}
