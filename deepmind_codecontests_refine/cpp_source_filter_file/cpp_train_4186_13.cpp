#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, k, sum = 0;
    cin >> n;
    string s;
    cin >> s;
    int st = 0, e = s.length() - 1;
    while (st <= e) {
      if (s[st] == '1' || s[e] == '1') break;
      st++;
      e--;
    }
    if (s[st] != '1' && s[e] != '1') {
      cout << n << endl;
      continue;
    }
    if (s[st] == '1') {
      cout << 2 * (n - st) << endl;
      continue;
    }
    if (s[st] == '1') {
      cout << 2 * (e + 1) << endl;
      continue;
    }
  }
}
