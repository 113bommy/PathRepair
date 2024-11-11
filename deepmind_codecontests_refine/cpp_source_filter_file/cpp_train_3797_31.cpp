#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 25;
int dyna[50][50][50][50];
bool A[26][50][50], B[26][50][50];
vector<pair<int, int> > e[26];
void fix(string s, bool A[26][50][50]) {
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 50; j++)
      for (int k = 0; k < 50; k++) A[i][j][k] = false;
  for (int i = 0; i < s.size(); i++) A[s[i] - 'a'][i][i] = true;
  for (int count = 0; count < s.size(); count++) {
    for (int i = 0; i < 26; i++)
      for (int j = 0; j < s.size(); j++)
        for (int k = j; k < s.size(); k++)
          for (int mid = j; mid < k; mid++)
            for (int next = 0; next < e[i].size(); next++)
              A[i][j][k] |= A[e[i][next].first][j][mid] &
                            A[e[i][next].second][mid + 1][k];
  }
}
int main() {
  string s1, s2;
  cin >> s1 >> s2;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string st;
    cin >> st;
    e[st[0] - 'a'].push_back(pair<int, int>(st[3] - 'a', st[4] - 'a'));
  }
  fix(s1, A);
  fix(s2, B);
  for (int i = 0; i < 50; i++)
    for (int j = 0; j < 50; j++)
      for (int k = 0; k < 50; k++)
        for (int l = 0; l < 50; l++) dyna[i][j][k][l] = INF;
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < s1.size(); j++)
      for (int k = j; k < s1.size(); k++)
        for (int j2 = 0; j2 < s2.size(); j2++)
          for (int k2 = j2; k2 < s2.size(); k2++)
            if (A[i][j][k] && A[i][j2][k2]) dyna[j][k][j2][k2] = 1;
  for (int i = s1.size() - 1; i >= 0; i--)
    for (int j = i; j < s1.size(); j++)
      for (int i2 = s2.size() - 1; i2 >= 0; i2--)
        for (int j2 = i2; j2 < s2.size(); j2++)
          for (int x = i; x < j; x++)
            for (int y = i2; y < j2; y++)
              dyna[i][j][i2][j2] =
                  min(dyna[i][j][i2][j2],
                      dyna[i][x][i2][y] + dyna[x + 1][j][y + 1][j2]);
  int ans = dyna[0][s1.size() - 1][0][s2.size() - 1];
  if (ans == INF)
    cout << -1 << endl;
  else
    cout << ans << endl;
}
