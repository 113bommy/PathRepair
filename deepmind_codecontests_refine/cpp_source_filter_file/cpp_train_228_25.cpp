#include <bits/stdc++.h>
using namespace std;
int smen[200001];
string s;
int vf[26];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t, n, m, i, x;
  cin >> t;
  for (int l = 1; l <= t; l++) {
    cin >> n >> m >> s;
    for (i = 0; i <= n; i++) smen[i] = 0;
    for (i = 0; i < 26; i++) vf[i] = 0;
    smen[0] = 1;
    smen[n] = -1;
    for (i = 1; i <= m; i++) {
      cin >> x;
      smen[0]++;
      smen[x]--;
    }
    for (i = 0; i < n; i++) {
      if (i) smen[i] += smen[i - 1];
      vf[s[i] - 'a'] += smen[i];
    }
    for (i = 0; i < 25; i++) cout << vf[i] << " ";
    cout << '\n';
  }
  return 0;
}
