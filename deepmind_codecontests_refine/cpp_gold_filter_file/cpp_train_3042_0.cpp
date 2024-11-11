#include <bits/stdc++.h>
using namespace std;
int psum[26][200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  string s;
  int q;
  cin >> s >> q;
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < 26; j++) {
      if (j + 'a' == s[i])
        psum[j][i + 1] = psum[j][i] + 1;
      else
        psum[j][i + 1] = psum[j][i];
    }
  }
  while (q--) {
    int l, r;
    cin >> l >> r;
    if (l == r)
      cout << "Yes\n";
    else if (s[l - 1] != s[r - 1])
      cout << "Yes\n";
    else if (s[l - 1] == s[r - 1]) {
      int cnt = 0;
      for (int i = 0; i < 26; i++) cnt += (psum[i][r] - psum[i][l] > 0);
      if (cnt >= 3)
        cout << "Yes\n";
      else
        cout << "No\n";
    }
  }
  return 0;
}
