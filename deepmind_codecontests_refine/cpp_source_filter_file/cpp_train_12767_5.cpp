#include <bits/stdc++.h>
using namespace std;
string ans[256][3];
string ans2[256][3];
inline string bests(string p1, string p2) {
  if (p1 == "") return p2;
  if (p2 == "") return p1;
  if (p1.length() < p2.length()) return p1;
  if (p2.length() < p1.length()) return p2;
  if (p1 < p2) return p1;
  return p2;
}
bool dd[256][6];
int main() {
  ans[240][2] = "x";
  ans[204][2] = "y";
  ans[170][2] = "z";
  while (1) {
    bool done = 1;
    for (int i = 0; i <= 255; ++i) {
      if (ans[i][0] == "" && ans[i][1] == "" && ans[i][2] == "") {
        done = 0;
        break;
      }
    }
    if (done) break;
    for (int i = 0; i <= 255; ++i)
      for (int j = 0; j <= 2; ++j) {
        if (ans[i][j] == "") continue;
        if (j < 2) {
          ans2[i ^ 255][2] = bests(ans2[i ^ 255][2], "!(" + ans[i][j] + ")");
        } else {
          ans2[i ^ 255][2] = bests(ans2[i ^ 255][2], "!" + ans[i][j]);
        }
        if (j < 2 && ans[i][2] == "") {
          ans2[i][2] = bests(ans2[i][2], "(" + ans[i][j] + ")");
        }
        for (int k = 0; k <= 255; ++k)
          for (int l = 0; l <= 2; ++l)
            if (ans[k][l] != "") {
              if (1) {
                ans2[i | k][0] =
                    bests(ans2[i | k][0], ans[i][j] + "|" + ans[k][l]);
              }
              if (j > 0 && l > 0) {
                ans2[i & k][1] =
                    bests(ans2[i & k][1], ans[i][j] + "&" + ans[k][l]);
              }
            }
      }
    for (int i = 0; i <= 255; ++i)
      for (int j = 0; j <= 2; ++j) ans[i][j] = bests(ans[i][j], ans2[i][j]);
  }
  int q;
  cin >> q;
  while (q--) {
    string s;
    cin >> s;
    int mask = 0;
    for (int i = 0; i <= 7; ++i)
      if (s[i] == '1') mask += (1 << i);
    cout << bests(ans[mask][0], bests(ans[mask][1], ans[mask][2])) << '\n';
  }
}
