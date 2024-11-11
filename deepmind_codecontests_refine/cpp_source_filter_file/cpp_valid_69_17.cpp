#include <bits/stdc++.h>
using namespace std;
string pow2[70];
void precalc() {
  int i = 1;
  int cur = 0;
  while (cur < 61) {
    pow2[cur] = to_string(i);
    i *= 2;
    cur++;
  }
}
long long calc(string a, string b) {
  int i = 0, j = 0;
  while (i < a.length() && j < b.length()) {
    if (a[i] == b[j]) {
      j++;
    }
    i++;
  }
  return b.length() - j + a.length() - j;
}
int main() {
  int q;
  precalc();
  cin >> q;
  while (q--) {
    string s1;
    cin >> s1;
    long long ans = 10;
    for (int i = 0; i < 60; i++) {
      ans = min(ans, calc(s1, pow2[i]));
    }
    cout << ans << '\n';
    ;
  }
  return 0;
}
