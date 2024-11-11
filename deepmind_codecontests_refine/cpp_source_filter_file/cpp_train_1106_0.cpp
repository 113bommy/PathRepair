#include <bits/stdc++.h>
using namespace std;
int k, n, dif[5000];
string s[5000], S[5000];
set<char> z;
bool ok0 = 0;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> k >> n;
  for (int i = 0; i < k; i++) {
    cin >> s[i];
    S[i] = s[i];
    for (char c : s[i]) z.insert(c);
    sort(S[i].begin(), S[i].end());
    if (i > 0 && S[i] != S[i - 1]) {
      cout << -1;
      return 0;
    }
  }
  if (z.size() != n) ok0 = 1;
  for (int i = 0; i < k; i++) {
    for (int j = 0; j < n; j++) {
      if (s[0][j] != s[i][j]) dif[i]++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      bool ok = 1;
      for (int a = 1; a < k; a++) {
        int d = dif[a];
        if (s[a][i] != s[0][i]) d--;
        if (s[a][j] != s[0][i]) d++;
        if (s[a][j] != s[0][j]) d--;
        if (s[a][i] != s[0][j]) d++;
        if (d != 2 && (d != 0 || ok0)) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        swap(s[0][i], s[0][j]);
        cout << s[0];
        return 0;
      }
    }
  }
  cout << -1;
  return 0;
}
