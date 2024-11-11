#include <bits/stdc++.h>
using namespace std;
string str[4];
int kv, len[4], vpos[4], vlen[4], scm[4];
bool match[4][4];
bool ifvow(char c) {
  if (c == 'a')
    return true;
  else if (c == 'e')
    return true;
  else if (c == 'i')
    return true;
  else if (c == 'o')
    return true;
  else if (c == 'u')
    return true;
  return false;
}
void loadvpos() {
  bool dontstopit;
  int tk;
  for (int i = 0; i < 4; i++) {
    vpos[i] = -1;
    tk = 0;
    dontstopit = true;
    for (int j = len[i] - 1; j >= 0 && dontstopit; j--)
      if (ifvow(str[i][j])) {
        tk++;
        if (tk == kv) {
          vpos[i] = j;
          vlen[i] = len[i] - j;
          dontstopit = false;
        }
      }
  }
}
void loadmatch() {
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++)
      if (i != j) {
        if (vpos[i] == -1 || vpos[j] == -1) {
          match[i][j] = false;
          match[j][i] = false;
        } else if (vlen[i] != vlen[j]) {
          match[i][j] = false;
          match[j][i] = false;
        } else {
          match[i][j] = true;
          match[j][i] = true;
          for (int ii = vpos[i], jj = vpos[j]; ii < vlen[i]; ii++, jj++)
            if (str[i][ii] != str[j][jj]) {
              match[i][j] = false;
              match[j][i] = false;
            }
        }
      }
  return;
}
void doit() {
  cin >> str[0] >> str[1] >> str[2] >> str[3];
  len[0] = str[0].size();
  len[1] = str[1].size();
  len[2] = str[2].size();
  len[3] = str[3].size();
  loadvpos();
  loadmatch();
  if (match[0][1] && match[1][2] && match[2][3]) {
    scm[0]++;
  }
  if (match[0][1] && match[2][3]) {
    scm[1]++;
  }
  if (match[0][2] && match[1][3]) {
    scm[2]++;
  }
  if (match[0][3] && match[1][2]) {
    scm[3]++;
  }
}
int main() {
  int n;
  cin >> n >> kv;
  memset(scm, 0, sizeof(scm));
  for (int i = 0; i < n; i++) {
    doit();
  }
  if (scm[0] == n)
    cout << "aaaa" << endl;
  else if (scm[1] == n)
    cout << "aabb" << endl;
  else if (scm[2] == n)
    cout << "abab" << endl;
  else if (scm[3] == n)
    cout << "abba" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
