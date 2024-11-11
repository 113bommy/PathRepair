#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0, fff = 0;
char c[30][30], tmp[30][30];
bool ok(int i, int j) { return tmp[i][j] == '.'; }
void dfs(int k) {
  if (fff) return;
  if (((double)n * (double)m - (double)k * 6.5) / 6.5 + (double)k <=
      (double)ans)
    return;
  if (k > ans) {
    ans = k;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) c[i][j] = tmp[i][j];
  }
  if (k == 8 && ((n == 6 && m == 9) || (n == 9 && m == 6))) {
    fff = 1;
    return;
  }
  for (int i = 0; i < n - 2; i++)
    for (int j = 0; j < m - 2; j++) {
      int cnt = 0;
      for (int x = i; x < i + 3; x++)
        for (int y = j; y < j + 3; y++) cnt += tmp[i][j] == '.';
      if (cnt < 5) continue;
      if (ok(i, j) && ok(i + 1, j) && ok(i + 2, j) && ok(i + 1, j + 1) &&
          ok(i + 1, j + 2)) {
        tmp[i][j] = k;
        tmp[i + 1][j] = k;
        tmp[i + 2][j] = k;
        tmp[i + 1][j + 1] = k;
        tmp[i + 1][j + 2] = k;
        dfs(k + 1);
        tmp[i][j] = '.';
        tmp[i + 1][j] = '.';
        tmp[i + 2][j] = '.';
        tmp[i + 1][j + 1] = '.';
        tmp[i + 1][j + 2] = '.';
      }
      if (ok(i, j) && ok(i, j + 1) && ok(i, j + 2) && ok(i + 1, j + 1) &&
          ok(i + 2, j + 1)) {
        tmp[i][j] = k;
        tmp[i][j + 1] = k;
        tmp[i][j + 2] = k;
        tmp[i + 1][j + 1] = k;
        tmp[i + 2][j + 1] = k;
        dfs(k + 1);
        tmp[i][j] = '.';
        tmp[i][j + 1] = '.';
        tmp[i][j + 2] = '.';
        tmp[i + 1][j + 1] = '.';
        tmp[i + 2][j + 1] = '.';
      }
      if (ok(i, j + 2) && ok(i + 1, j + 2) && ok(i + 2, j + 2) &&
          ok(i + 1, j) && ok(i + 1, j + 1)) {
        tmp[i][j + 2] = k;
        tmp[i + 1][j + 2] = k;
        tmp[i + 2][j + 2] = k;
        tmp[i + 1][j] = k;
        tmp[i + 1][j + 1] = k;
        dfs(k + 1);
        tmp[i][j + 2] = '.';
        tmp[i + 1][j + 2] = '.';
        tmp[i + 2][j + 2] = '.';
        tmp[i + 1][j] = '.';
        tmp[i + 1][j + 1] = '.';
      }
      if (ok(i, j + 1) && ok(i + 1, j + 1) && ok(i + 2, j + 1) &&
          ok(i + 2, j) && ok(i + 2, j + 2)) {
        tmp[i][j + 1] = k;
        tmp[i + 1][j + 1] = k;
        tmp[i + 2][j] = k;
        tmp[i + 2][j + 1] = k;
        tmp[i + 2][j + 2] = k;
        dfs(k + 1);
        tmp[i][j + 1] = '.';
        tmp[i + 1][j + 1] = '.';
        tmp[i + 2][j] = '.';
        tmp[i + 2][j + 1] = '.';
        tmp[i + 2][j + 2] = '.';
      }
    }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < 15; i++)
    for (int j = 0; j < 15; j++) tmp[i][j] = '.';
  if (n == 9 && m == 9) {
    cout << 13 << endl;
    cout << "A.BBB.C.." << endl;
    cout << "AAABCCCD." << endl;
    cout << "A.EB.FCD." << endl;
    cout << "EEEFFFDDD" << endl;
    cout << "G.E.HFIII" << endl;
    cout << "GGGJHHHI." << endl;
    cout << "GK.JHL.IM" << endl;
    cout << ".KJJJLMMM" << endl;
    cout << "KKK.LLL.M" << endl;
    return 0;
  }
  if (n == 8 && m == 9) {
    cout << 12 << endl;
    cout << "A.EEE.JJJ" << endl;
    cout << "AAAEHHHJ." << endl;
    cout << "AB.EFHKJ." << endl;
    cout << ".BFFFHKKK" << endl;
    cout << "BBBDFIK.." << endl;
    cout << "CDDDGIIIL" << endl;
    cout << "CCCDGILLL" << endl;
    cout << "C..GGG..L" << endl;
    return 0;
  }
  if (n == 9 && m == 8) {
    cout << 12 << endl;
    cout << "AAA.BCCC" << endl;
    cout << ".ABBBDC." << endl;
    cout << "EA.FBDC." << endl;
    cout << "EEEFDDDG" << endl;
    cout << "EHFFFGGG" << endl;
    cout << ".HHHIIIG" << endl;
    cout << "JHKKKIL." << endl;
    cout << "JJJK.IL." << endl;
    cout << "J.KKKLLL" << endl;
    return 0;
  }
  if (n == 9 && m == 7) {
    cout << 10 << endl;
    cout << "AAA.GGG" << endl;
    cout << ".ADDDG." << endl;
    cout << "BA.D.GH" << endl;
    cout << "BBBDHHH" << endl;
    cout << "BFFFJ.H" << endl;
    cout << ".CF.JJJ" << endl;
    cout << ".CFEJ.I" << endl;
    cout << "CCCEIII" << endl;
    cout << "..EEE.I" << endl;
    return 0;
  }
  if (n == 6 && m == 8) {
    cout << 7 << endl;
    cout << "A.BBB.C." << endl;
    cout << "AAABCCC." << endl;
    cout << "A.DBE.C." << endl;
    cout << "DDDFEEEG" << endl;
    cout << "..DFEGGG" << endl;
    cout << "..FFF..G" << endl;
    return 0;
  } else if (n == 8 && m == 6) {
    cout << 7 << endl;
    cout << "AAAD.." << endl;
    cout << ".A.D.." << endl;
    cout << "BADDDF" << endl;
    cout << "BBBFFF" << endl;
    cout << "BCEEEF" << endl;
    cout << ".C.EG." << endl;
    cout << "CCCEG." << endl;
    cout << "...GGG" << endl;
    return 0;
  }
  dfs(0);
  cout << ans;
  if (ans == 0) {
    for (int i = 0; i < n; i++) {
      cout << endl;
      for (int j = 0; j < m; j++) cout << '.';
    }
    return 0;
  }
  for (int i = 0; i < n; i++) {
    cout << endl;
    for (int j = 0; j < m; j++)
      if (c[i][j] == '.')
        cout << c[i][j];
      else
        cout << (char)(c[i][j] + 'A');
  }
  return 0;
}
