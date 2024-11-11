#include <bits/stdc++.h>
using namespace std;
int M[4][4];
const int MAXLENGTH = 500111;
string s[4];
char inv(char c) {
  if (c == 'a') return 'b';
  return 'a';
}
int main() {
  int mn = 1000111000;
  for (int i = 0; i < 4; i++)
    for (int j = i + 1; j < 4; j++) scanf("%d", &M[i][j]);
  for (int k = 0; k <= MAXLENGTH; k++) {
    M[0][1] -= k;
    M[0][2] -= k;
    M[0][3] -= k;
    int x[7];
    x[6] = k;
    x[5] = (M[0][1] - M[1][2] + M[0][2]) / 2;
    x[4] = (M[0][1] - M[1][3] + M[0][3]) / 2;
    x[3] = M[1][3] - M[0][3];
    x[3] += x[4];
    x[3] -= x[5];
    x[2] = (M[0][2] - M[2][3] + M[0][3]) / 2;
    x[1] = M[0][2];
    x[1] -= x[2];
    x[1] -= x[5];
    x[0] = M[0][3];
    x[0] -= x[2];
    x[0] -= x[4];
    M[0][1] += k;
    M[0][2] += k;
    M[0][3] += k;
    if (x[3] + x[4] + x[5] + x[6] != M[0][1]) continue;
    if (x[1] + x[2] + x[5] + x[6] != M[0][2]) continue;
    if (x[0] + x[2] + x[4] + x[6] != M[0][3]) continue;
    if (x[1] + x[2] + x[3] + x[4] != M[1][2]) continue;
    if (x[0] + x[2] + x[3] + x[5] != M[1][3]) continue;
    if (x[0] + x[1] + x[4] + x[5] != M[2][3]) continue;
    bool flag = true;
    int len = 0;
    for (int i = 0; i < 6; i++) {
      if (x[i] < 0) {
        flag = false;
        break;
      }
      len += x[i];
    }
    if (!flag) continue;
    if (len < mn) {
      mn = len;
      s[0] = s[1] = s[2] = s[3] = "";
      for (int k = 0; k < 7; k++) {
        int bm = k + 1;
        for (int j = 0; j < x[k]; j++) {
          for (int i = 0; i < 4; i++) {
            s[3 - i].push_back((bm & (1 << i)) ? 'b' : 'a');
          }
        }
      }
    }
  }
  if (mn == 1000111000)
    printf("-1\n");
  else {
    printf("%d\n", mn);
    for (int i = 0; i < 4; i++) printf("%s\n", s[i].c_str());
  }
  return 0;
}
