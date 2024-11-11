#include <bits/stdc++.h>
const int maxl = 11;
const int maxn = 1e5 + 1e2;
std::vector<int> fen[maxl][maxl][4];
int conv[256];
void update(int a, int b, int c, int ind, int change) {
  while (ind < fen[a][b][c].size()) {
    fen[a][b][c][ind] += change;
    ind += ind & -ind;
  }
}
int query(int a, int b, int c, int ind) {
  int res = 0;
  while (ind > 0) {
    res += fen[a][b][c][ind];
    ind -= ind & -ind;
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::string s;
  std::cin >> s;
  int n = s.size();
  conv['A'] = 0;
  conv['C'] = 1;
  conv['G'] = 2;
  conv['T'] = 3;
  for (int i = 1; i <= 10; i++) {
    for (int j = 0; j < i; j++) {
      fen[i][j][0].resize(n / i + 5);
      fen[i][j][1].resize(n / i + 5);
      fen[i][j][2].resize(n / i + 5);
      fen[i][j][3].resize(n / i + 5);
      for (int k = j, ind = 1; k < n; k += i, ind++) {
        update(i, j, conv[s[k]], ind, 1);
      }
    }
  }
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int t;
    std::cin >> t;
    if (t == 1) {
      int pos;
      char c;
      std::cin >> pos >> c;
      pos--;
      for (int i = 1; i <= 10; i++) {
        int posind = pos / i + 1;
        update(i, pos % i, conv[s[pos]], posind, -1);
        update(i, pos % i, conv[c], posind, 1);
      }
      s[pos] = c;
    } else {
      int l, r;
      std::cin >> l >> r;
      l--, r--;
      std::string sub;
      std::cin >> sub;
      int subn = sub.size();
      int res = 0;
      while (l <= r and (r - l + 1) % subn != 0) {
        res += (sub[(r - l) % subn] == s[r]);
        r--;
      }
      if (l < r) {
        for (int i = 0; i < subn; i++) {
          int a = l + i;
          a -= subn;
          int b = r - (subn - 1 - i);
          int aind = a / subn + 1;
          int bind = b / subn + 1;
          res += query(subn, b % subn, conv[sub[i]], bind);
          if (a >= 0) {
            res -= query(subn, a % subn, conv[sub[i]], aind);
          }
        }
      }
      std::cout << res << '\n';
    }
  }
}
