#include <bits/stdc++.h>

using namespace std;

string s, t;
int nex[201010][27];

int main() {
  cin >> s >> t;
  int s_sz = s.size();
  int t_sz = t.size();
  s = s + s;
  for (int i = 0; i < 26; i++) nex[2 * s_sz][i] = 2 * s_sz;
  for (int i = 2 * s_sz - 1; 0 <= i; i--) {
    for (int j = 0; j < 26; j++) {
      nex[i][j] = nex[i + 1][j];
    }
    nex[i][s[i] - 'a'] = i + 1;
  }

  long long cur = 0;
  for (int i = 0; i < t.size(); i++) {
    char c = t[i] - 'a';
    int x = cur % s_sz;
    if (nex[x][c] == 2 * s_sz) {
      cout << -1 << endl;
      return 0;
    }
    cur += nex[x][c] - x;
  }

  cout << cur << endl;

  return 0;
}