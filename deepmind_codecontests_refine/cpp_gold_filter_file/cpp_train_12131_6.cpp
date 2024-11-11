#include <bits/stdc++.h>
using namespace std;
int m, n, i, j, k;
int L[26][100000], R[26][100000];
string s, t;
int main() {
  cin >> n >> m;
  cin >> t;
  for (i = 0; i < m; i++) {
    for (j = 0; j < 26; j++) {
      if (j != t[i] - 'a') {
        if (i == 0)
          L[j][i] = -1000000;
        else
          L[j][i] = L[j][i - 1];
      } else
        L[j][i] = i;
    }
  }
  for (i = m - 1; i >= 0; i--) {
    for (j = 0; j < 26; j++) {
      if (j != t[i] - 'a') {
        if (i == m - 1)
          R[j][i] = 1000000;
        else
          R[j][i] = R[j][i + 1];
      } else
        R[j][i] = i;
    }
  }
  for (i = 0; i < n; i++) {
    cin >> s;
    long long answer = 0, d;
    for (j = 0; j < s.size(); j++) {
      k = s[j] - 'a';
      if (j >= m)
        d = j - L[k][m - 1];
      else
        d = min(j - L[k][j], R[k][j] - j);
      if (d >= 500000) d = s.size();
      answer += d;
    }
    cout << answer << endl;
  }
  return 0;
}
