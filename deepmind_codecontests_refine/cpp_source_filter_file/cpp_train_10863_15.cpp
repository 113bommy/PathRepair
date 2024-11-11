#include <bits/stdc++.h>
using namespace std;
double dpsm[200001][26] = {0};
double dpfm[200001][26] = {0};
double ans = 0;
int main() {
  int n;
  cin >> n;
  string s, f;
  cin >> s >> f;
  dpsm[0][s[0] - 'A'] = 1;
  dpfm[0][f[0] - 'A'] = 1;
  for (int i = 0; i < 26; ++i) {
    char c = 'A' + i;
    for (int j = 1; j < s.size(); ++j) {
      if (s[j] == c) {
        dpsm[j][i] = (dpsm[j - 1][i] + j + 1);
      } else {
        dpsm[j][i] = dpsm[j - 1][i];
      }
      if (f[j] == c) {
        dpfm[j][i] = dpfm[j - 1][i] + j + 1;
      } else {
        dpfm[j][i] = dpfm[j - 1][i];
      }
    }
  }
  double r = (n) * (n + 1) * (2 * n + 1) / 6.0;
  for (int j = 0; j < s.size(); ++j) {
    ans += 1.0 * (s.size() - j) * dpfm[j][s[j] - 'A'] / r;
  }
  for (int j = 0; j < f.size(); ++j) {
    if (f[j] == s[j]) {
      ans += 1.0 * (s.size() - j) * (dpsm[j][f[j] - 'A'] - j - 1) / r;
    } else {
      ans += 1.0 * (s.size() - j) * dpsm[j][f[j] - 'A'] / r;
    }
  }
  printf("%.9f\n", ans);
  return 0;
}
