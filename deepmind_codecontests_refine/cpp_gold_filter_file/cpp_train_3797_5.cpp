#include <bits/stdc++.h>
using namespace std;
int m, n, j, k, l, i, o, p, __t, lena, lenb;
string sa, sb, s;
vector<pair<int, int> > change[100];
int A[2][51][51][51];
int F[51][51];
int DFS(int l, int r, int tag, int M) {
  if (A[tag][l][r][M] != -1) return A[tag][l][r][M];
  if (l == r && s[l] != 'a' + M) return A[tag][l][r][M] = 0;
  if (l == r && s[l] == 'a' + M) return A[tag][l][r][M] = 1;
  bool ret = 0;
  for (int i = 0; i < change[M].size(); i++) {
    int a1 = change[M][i].first;
    int a2 = change[M][i].second;
    for (int j = l; j < r; j++)
      ret = max(DFS(l, j, tag, a1) && DFS(j + 1, r, tag, a2), ret);
  }
  return A[tag][l][r][M] = ret;
}
int main() {
  cin >> sa >> sb;
  lena = sa.length();
  lenb = sb.length();
  cin >> m;
  for (int i = 1; i <= m; i++) {
    cin >> s;
    pair<int, int> a(s[3] - 'a', s[4] - 'a');
    change[s[0] - 'a'].push_back(a);
  }
  memset(A, -1, sizeof A);
  s = sa;
  for (int o = 1; o <= lena; o++)
    for (int l = 0; l + o - 1 < lena; l++)
      for (int i = 0; i < 26; i++) DFS(l, l + o - 1, 0, i);
  s = sb;
  for (int o = 1; o <= lenb; o++)
    for (int l = 0; l + o - 1 < lenb; l++)
      for (int i = 0; i < 26; i++) DFS(l, l + o - 1, 1, i);
  memset(F, -1, sizeof F);
  F[0][0] = 0;
  for (int i = 0; i < lena; i++)
    for (int j = 0; j < lenb; j++)
      if (F[i][j] != -1) {
        for (int ch = 0; ch < 26; ch++)
          for (int k = i; k < lena; k++)
            if (A[0][i][k][ch] == 1)
              for (int l = j; l < lenb; l++)
                if (A[1][j][l][ch] == 1) {
                  if (F[k + 1][l + 1] == -1)
                    F[k + 1][l + 1] = F[i][j] + 1;
                  else
                    F[k + 1][l + 1] = min(F[k + 1][l + 1], F[i][j] + 1);
                }
      }
  cout << F[lena][lenb] << endl;
}
