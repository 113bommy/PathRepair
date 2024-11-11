#include <bits/stdc++.h>
using namespace std;
const int N = 301;
string ans[N][3];
int T;
bool mknew;
void updata(string &a, string &b) {
  if (a == "" || b.length() < a.length() ||
      (b.length() == a.length() && b < a)) {
    mknew = true;
    a = b;
  }
}
void get() {
  ans[(1 << 4) - 1][0] = "x";
  ans[(1 << 2) - 1 + (1 << 6) - (1 << 4)][0] = "y";
  ans[(1 << 0) + (1 << 2) + (1 << 4) + (1 << 6)][0] = "z";
  mknew = true;
  while (mknew) {
    mknew = false;
    for (int i = 0; i < 256; ++i)
      for (int j = 0; j <= 2; ++j) {
        if (ans[i][j] == "") continue;
        string s = ans[i][j];
        if (j > 0) s = "(" + s + ")";
        s = "!" + s;
        updata(ans[i ^ 255][0], s);
        for (int ii = 0; ii < 256; ++ii)
          for (int jj = 0; jj <= 2; ++jj) {
            if (ans[ii][jj] == "") continue;
            for (int op = 1; op <= 2; ++op) {
              s = ans[i][j];
              if (j >= op) s = "(" + s + ")";
              string t = ans[ii][jj];
              if (jj >= op) t = "(" + t + ")";
              string w;
              if (op == 1) {
                w = s + "&" + t;
                updata(ans[i & ii][op], w);
              } else {
                w = s + "|" + t;
                updata(ans[i | ii][op], w);
              }
            }
          }
      }
  }
}
int main() {
  get();
  cin >> T;
  while (T--) {
    string p;
    cin >> p;
    int op = 0;
    for (int i = 0; i < 8; ++i) op = (op << 1) + (p[i] - '0');
    string anss = "";
    for (int i = 0; i < 3; ++i) updata(anss, ans[op][i]);
    cout << anss << endl;
  }
  return 0;
}
