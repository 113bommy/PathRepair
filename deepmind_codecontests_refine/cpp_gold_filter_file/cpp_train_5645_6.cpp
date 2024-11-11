#include <bits/stdc++.h>
using namespace std;
const int INF = 1000 * 1000 * 1000 + 7;
const long long LINF = INF * (long long)INF;
int cnt[27][200005];
int main() {
  string s;
  cin >> s;
  for (auto &first : s) first -= 'a';
  for (int c = 0; c < 26; c++)
    for (int i = 0; i < (int)(s.size()); i++)
      cnt[c][i] = (i ? cnt[c][i - 1] : 0) + (s[i] == c);
  int q;
  cin >> q;
  while (q--) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    if (l == r || s[l] != s[r]) {
      cout << "Yes" << endl;
      continue;
    }
    int ans = 0;
    for (int it = 0; it < 26; it++)
      ans += (cnt[it][r] - (l ? cnt[it][l - 1] : 0)) > 0;
    cout << (ans > 2 ? "Yes" : "No") << endl;
  }
}
