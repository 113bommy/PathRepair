#include <bits/stdc++.h>
using namespace std;
int p[5000][5000];
int n, m;
int main() {
  string s;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int k = 0;
    while (k < m) {
      while (k < m && s[k] == '0') k++;
      int t = k;
      if (k == m) break;
      while (k < m && s[k] == '1') k++;
      p[t][k - 1]++;
    }
  }
  for (int j = 0; j < m; j++)
    for (int i = m - 1; i > j; i--) p[j][i - 1] += p[j][i];
  for (int i = m - 1; i >= 0; i--)
    for (int j = 0; j < i; j++) p[j + 1][i] += p[j][i];
  int best = 0;
  for (int i = 0; i < m - 1; i++)
    for (int j = i; j < m - 1; j++) best = max(best, (j - i + 1) * p[i][j]);
  cout << best;
  return 0;
}
