#include <bits/stdc++.h>
using namespace std;
char c[7][51];
int b[7];
int v[7];
bool judge() {
  if (v[b[1]] + v[b[6]] - 1 != v[b[3]] || v[b[2]] + v[b[5]] - 1 != v[b[4]])
    return false;
  if (c[b[1]][v[b[1]] - 1] != c[b[4]][0] ||
      c[b[4]][v[b[4]] - 1] != c[b[6]][0] ||
      c[b[5]][v[b[5]] - 1] != c[b[6]][v[b[6]] - 1] ||
      c[b[2]][v[b[2]] - 1] != c[b[3]][0] ||
      c[b[3]][v[b[3]] - 1] != c[b[5]][0] || c[b[1]][0] != c[b[2]][0])
    return false;
  if (c[b[3]][v[b[1]] - 1] != c[b[4]][v[b[2]] - 1]) return false;
  return true;
}
char ans[101][51][51];
int main() {
  for (int i = 1; i <= 6; i++) {
    cin >> c[i];
    b[i] = i;
  }
  for (int i = 1; i <= 6; i++) {
    v[i] = strlen(c[b[i]]);
  }
  int s = 0;
  do {
    if (judge() == true) {
      s++;
      for (int i = 0; i <= v[b[4]] - 1; i++) {
        for (int j = 0; j <= v[b[3]] - 1; j++) {
          ans[s][i][j] = '.';
        }
      }
      for (int i = 0; i < v[b[1]]; i++) ans[s][0][i] = c[b[1]][i];
      for (int i = 0; i < v[b[2]]; i++) ans[s][i][0] = c[b[2]][i];
      for (int i = 0; i < v[b[3]]; i++) ans[s][v[b[2]] - 1][i] = c[b[3]][i];
      for (int i = 0; i < v[b[4]]; i++) ans[s][i][v[b[1]] - 1] = c[b[4]][i];
      for (int i = 0; i < v[b[5]]; i++)
        ans[s][v[b[2]] - 1 + i][v[b[3]] - 1] = c[b[5]][i];
      for (int i = 0; i < v[b[6]]; i++)
        ans[s][v[b[4]] - 1][v[b[1]] - 1 + i] = c[b[6]][i];
    }
  } while (next_permutation(b + 1, b + 1 + 6));
  int r = 0, minx = 1;
  if (s == 0) {
    cout << "Impossible";
    return 0;
  } else {
    for (int i = 2; i <= s; i++) {
      for (int j = 1; j <= 30; j++) {
        r = strcmp(ans[i][j], ans[1][j]);
        if (r > 0) {
          minx = i;
          break;
        } else if (r < 0) {
          break;
        }
      }
    }
  }
  for (int i = 0; i < 31; i++) {
    cout << ans[minx][i] << endl;
  }
  return 0;
}
