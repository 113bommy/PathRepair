#include <bits/stdc++.h>
using namespace std;
vector<char> v[26][5010];
int mp[5010][700];
int calc(int p, int q) { return 26 * p + q; }
int main() {
  string s;
  cin >> s;
  int len = s.length();
  for (int i = 0; i < len; i++) {
    int p = s[i] - 97;
    for (int j = 1; j < len; j++) {
      int q = (i + j) % len;
      v[p][j].push_back(s[q]);
      int pos = calc(p, s[q] - 97);
      mp[j][pos]++;
    }
  }
  int res = 0;
  for (int i = 0; i < 26; i++) {
    int maxx = 0;
    for (int j = 1; j < len; j++) {
      int qaq = 0;
      for (int k = 0; k < v[i][j].size(); k++) {
        int pos = calc(i, v[i][j][k] - 97);
        if (mp[j][pos] == 1) qaq++;
      }
      maxx = max(maxx, qaq);
    }
    res += maxx;
  }
  double ans = (double)res / len;
  printf("%.10f\n", ans);
  return 0;
}
