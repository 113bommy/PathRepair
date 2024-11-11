#include <bits/stdc++.h>
using namespace std;
using ld = long double;
int main() {
  string s;
  cin >> s;
  int l = s.size();
  vector<vector<vector<int>>> all(26, vector<vector<int>>(l, vector<int>(26)));
  map<int, int> cnt;
  for (int i = 0; i < l; i++) {
    int p = s[i] - 'a';
    cnt[p]++;
    for (int j = 0; j < l; j++) {
      all[p][j][s[(i + j) % l] - 'a']++;
    }
  }
  int res = 0;
  for (auto p : cnt) {
    int ma = 0;
    for (int i = 1; i < l; i++) {
      int c = 0;
      for (int j = 0; j < 26; j++) {
        c += all[p.first][i][j] == 1;
      }
      ma = max(ma, c);
    }
    res += ma;
  }
  cout << fixed << setprecision(10) << (ld)res / l << endl;
  return 0;
}
