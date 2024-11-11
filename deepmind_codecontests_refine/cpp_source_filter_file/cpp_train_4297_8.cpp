#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  int i, j, w, x, y;
  bool rhyme[4][4], scheme[5000][4];
  string str[4];
  map<int, string> name;
  name[0] = "aaaa";
  name[1] = "aabb";
  name[2] = "abab";
  name[3] = "abba";
  cin >> n >> k;
  for (i = 0; i < (n); i++) {
    for (j = 0; j < (4); j++) {
      cin >> str[j];
    }
    memset(rhyme, false, sizeof(rhyme));
    for (w = 0; w < (4); w++) {
      int ln = str[w].size();
      int cnt = 0;
      string suff = "";
      for (x = (ln - 1); x >= 0; x--) {
        if (str[w][x] == 'a' || str[w][x] == 'e' || str[w][x] == 'i' ||
            str[w][x] == 'o' || str[w][x] == 'u') {
          cnt++;
        }
        if (cnt == k) {
          suff = str[w].substr(x, ln - x + 1);
          break;
        }
      }
      if (cnt < k) {
        cout << "NO" << endl;
        return 0;
      }
      for (x = (w + 1); x < (4); x++) {
        int sz = str[x].size();
        cnt = 0;
        string ss = "";
        for (y = (sz - 1); y >= 0; y--) {
          if (str[x][y] == 'a' || str[x][y] == 'e' || str[x][y] == 'i' ||
              str[x][y] == 'o' || str[x][y] == 'u') {
            cnt++;
          }
          if (cnt == k) {
            ss = str[x].substr(y, sz - y + 1);
            if (ss == suff) {
              rhyme[w][x] = rhyme[x][w] = true;
            }
            break;
          }
        }
      }
    }
    if (rhyme[0][1] == true && rhyme[1][2] == true && rhyme[2][3] == true) {
      scheme[i][0] = true;
    }
    if (rhyme[0][1] == true && rhyme[2][3] == true) {
      scheme[i][1] = true;
    }
    if (rhyme[0][2] == true && rhyme[1][3] == true) {
      scheme[i][2] = true;
    }
    if (rhyme[0][3] == true && rhyme[1][2] == true) {
      scheme[i][1] = true;
    }
  }
  for (i = 0; i < (4); i++) {
    for (j = 0; j < (n); j++) {
      if (scheme[j][i] == false) {
        break;
      }
    }
    if (j == n) {
      cout << name[i] << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
