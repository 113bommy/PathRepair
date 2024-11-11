#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(0);
  cin.sync_with_stdio(0);
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) s[i] -= 'a';
  int n = s.size();
  vector<vector<vector<int> > > v(
      26, vector<vector<int> >(n - 1, vector<int>(26, 0)));
  for (int i = 0; i < s.size(); i++) {
    char c = s[i];
    auto &cur_v = v[c];
    for (int j = 0; j < n - 1; j++) {
      int k = (j + i) % n;
      cur_v[j][s[k]] += 1;
    }
  }
  cout << setprecision(9);
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    int Max = 0;
    for (int j = 0; j < n - 1; j++) {
      int tmp = 0;
      for (int k = 0; k < 26; k++) tmp += v[i][j][k] == 1;
      Max = max(Max, tmp);
    }
    ans += Max;
  }
  cout << fixed << (double)ans / n << endl;
  return 0;
}
