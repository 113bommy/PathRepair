#include <bits/stdc++.h>
using namespace std;
const int sz = 500;
struct block {
  int ans[11][11][26];
};
block b[sz];
string s;
int get(int l, int r, string& pat) {
  int ans = 0;
  int mod = pat.size();
  int nn = l / sz;
  if (l / sz == r / sz) {
    for (int i = l, j = 0; i < r + 1; i++, j++) {
      ans += (s[i] == pat[j % mod]);
    }
    return ans;
  }
  int ll = l;
  int j;
  for (j = 0; l % sz != 0; l++, j++) {
    ans += (s[l] == pat[j % mod]);
  }
  for (int k = r; (r + 1) % sz != 0; r--, k--) {
    ans += (s[r] == pat[(k - ll) % mod]);
  }
  int b1 = l / sz, b2 = r / sz;
  for (; b1 <= b2; b1++, j += sz) {
    for (int k = j % mod; k < j % mod + mod; k++) {
      ans += b[b1].ans[mod][(ll + k) % mod][pat[k % mod] - 'A'];
    }
  }
  return ans;
}
void update(int pos, char c) {
  int num = pos / sz;
  for (int i = 1; i <= 10; i++) {
    b[num].ans[i][pos % i][s[pos] - 'A']--;
    b[num].ans[i][pos % i][c - 'A']++;
  }
  s[pos] = c;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> s;
  for (int i = 0; i < s.size(); i += sz) {
    for (int k = i; k < i + sz and k < s.size(); k++) {
      for (int j = 1; j <= 10; j++) {
        b[i / sz].ans[j][k % j][s[k] - 'A']++;
      }
    }
  }
  int q;
  cin >> q;
  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int pos;
      cin >> pos;
      pos--;
      char c;
      cin >> c;
      update(pos, c);
    } else {
      int l, r;
      string pat;
      cin >> l >> r >> pat;
      l--, r--;
      cout << get(l, r, pat) << '\n';
    }
  }
  return 0;
}
