#include <bits/stdc++.h>
using namespace std;
int temp[1000], kmp[100000], kmp_turn[100000];
void KMP(int kmp[], string &s, string t) {
  int p;
  temp[0] = p = 0;
  for (int i = 1; i < t.length(); ++i) {
    while (p && t[p] != t[i]) {
      p = temp[p - 1];
    }
    temp[i] = p += (t[p] == t[i]);
  }
  t.push_back(0);
  kmp[0] = p = 0;
  for (int i = 0; i < s.length(); ++i) {
    while (p && t[p] != s[i]) {
      p = temp[p - 1];
    }
    kmp[i] = p += (t[p] == s[i]);
  }
}
int main() {
  string s;
  while (cin >> s) {
    string s_turn(s.rbegin(), s.rend()), p;
    int n, ans = 0;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> p;
      if (p.length() <= 1) {
        continue;
      }
      string p_turn(p.rbegin(), p.rend());
      KMP(kmp, s, p);
      KMP(kmp_turn, s_turn, p_turn);
      for (int i = 1; i < p.length(); ++i) {
        kmp_turn[i] = max(kmp_turn[i], kmp_turn[i - 1]);
      }
      int maxkmp = 0;
      for (int i = 0, j = s.length() - 2; j >= 0; ++i, --j) {
        maxkmp = max(maxkmp, kmp[i]);
        if (maxkmp && kmp_turn[j] && maxkmp + kmp_turn[j] >= p.length()) {
          ++ans;
          break;
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
