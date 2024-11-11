#include <bits/stdc++.h>
const int N = 100010;
const int inf = 0x3f3f3f3f;
using namespace std;
string str[6];
struct data {
  vector<string> vt;
  bool operator<(const data &r) const {
    for (int i = 0; i < min(((vt).size()), ((r.vt).size())); i++)
      if (vt[i] != r.vt[i]) return vt[i] < r.vt[i];
    return ((vt).size()) < ((r.vt).size());
  }
} ret;
int main() {
  for (int i = 0; i < 6; i++) cin >> str[i];
  sort(str, str + 6);
  bool r = 0;
  do {
    bool f = 0;
    for (int i = 0; i < 6; i++)
      if (((str[i]).size()) < 3) f = 1;
    if (f) break;
    if (((str[0]).size()) + ((str[2]).size()) != ((str[1]).size()) + 1)
      continue;
    if (((str[3]).size()) + ((str[5]).size()) != ((str[4]).size()) + 1)
      continue;
    if (str[0][0] != str[3][0]) continue;
    if (str[3][((str[3]).size()) - 1] != str[1][0]) continue;
    if (str[0][((str[0]).size()) - 1] != str[4][0]) continue;
    if (str[4][((str[4]).size()) - 1] != str[2][0]) continue;
    if (str[1][((str[1]).size()) - 1] != str[5][0]) continue;
    if (str[2][((str[2]).size()) - 1] != str[5][((str[5]).size()) - 1])
      continue;
    if (str[1][((str[0]).size()) - 1] != str[4][((str[3]).size()) - 1])
      continue;
    data tmp;
    for (int i = 0; i < ((str[1]).size()); i++) {
      string t;
      if (i < ((str[0]).size()))
        t += str[0][i];
      else
        t += '.';
      if (i < ((str[0]).size()) - 1) {
        for (int j = 1; j < ((str[3]).size()) - 1; j++)
          if (i == 0)
            t += str[3][j];
          else
            t += '.';
        t += str[1][i];
        for (int j = ((str[3]).size()); j < ((str[4]).size()); j++) t += '.';
      } else if (i == ((str[0]).size()) - 1) {
        for (int j = 1; j < ((str[4]).size()); j++) t += str[4][j];
      } else {
        for (int j = 1; j < ((str[3]).size()) - 1; j++) t += '.';
        t += str[1][i];
        for (int j = ((str[3]).size()); j < ((str[4]).size()) - 1; j++)
          if (i != ((str[1]).size()) - 1)
            t += '.';
          else
            t += str[5][j - ((str[3]).size()) + 1];
        t += str[2][i - ((str[0]).size()) + 1];
      }
      tmp.vt.push_back(t);
    }
    if (r == 0) ret = tmp, r = 1;
    if (tmp < ret) ret = tmp;
  } while (next_permutation(str, str + 6));
  if (!r)
    cout << "Impossible" << endl;
  else {
    for (int i = 0; i < ((ret.vt).size()); i++) cout << ret.vt[i] << endl;
  }
  return 0;
}
