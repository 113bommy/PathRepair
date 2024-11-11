#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool is_possible = false;
  int res_i, res_j;
  for (int i = 0; i < 27; i++)
    for (int j = i + 2; j < 27; j++)
      if (s[i] == s[j]) {
        is_possible = true;
        res_i = i;
        res_j = j;
        break;
      }
  if (!is_possible) {
    cout << "Impossible" << endl;
    return 0;
  }
  vector<vector<char> > res(2, vector<char>(' ', 13));
  int i, j = res_i;
  for (i = (res_i + 26 - res_j) / 2; i >= 0 && j >= 0; i--, j--)
    res[1][i] = s[j];
  for (i = 0; j >= 0; i++, j--) res[0][i] = s[j];
  j = res_i + 1;
  for (i = (res_i + 26 - res_j) / 2 + 1; i < 13; i++, j++) res[1][i] = s[j];
  for (i = 12; j <= 26 && i >= 0; i--, j++)
    if (j == res_j) {
      i++;
      continue;
    } else
      res[0][i] = s[j];
  for (i = 0; j <= 26; i++, j++) res[1][i] = s[j];
  for (int i = 0; i < 13; i++) cout << res[0][i];
  cout << endl;
  for (int i = 0; i < 13; i++) cout << res[1][i];
}
