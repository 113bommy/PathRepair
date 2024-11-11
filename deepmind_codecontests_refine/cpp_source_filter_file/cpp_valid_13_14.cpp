#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m, k;
    cin >> n >> m >> k;
    int a = 0;
    if (n % 2) {
      if (m / 2 > k) {
        cout << "NO" << endl;
        continue;
      } else {
        a += m / 2;
      }
    } else if (m % 2) {
      if (n * m / 2 - n / 2 < k) {
        cout << "NO" << endl;
        continue;
      }
    }
    k -= a;
    if (k % 2) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES"
         << "\n";
    k += a;
    vector<char> ch(26);
    for (int j = 0; j < 26; j++) ch[j] = 'a' + j;
    vector<vector<char>> v(n, vector<char>(m, '0'));
    if (n % 2) {
      int p = 0;
      for (int j = 0; j < m && k > 0; j += 2) {
        if (j > 0 && v[0][j - 1] == ch[p % 26]) p++;
        v[0][j] = ch[p % 26];
        v[0][j + 1] = ch[p % 26];
        p++;
        k--;
      }
      int r = 1, c = 0;
      while (k > 0) {
        for (int j = 0; j < m && k > 0; j += 2) {
          if (r > 0 && v[r - 1][j] == ch[p % 26]) p++;
          if (j > 0 && v[r][j - 1] == ch[p % 26]) p++;
          v[r][j] = ch[p % 26];
          v[r][j + 1] = ch[p % 26];
          p++;
          v[r + 1][j] = ch[p % 26];
          v[r + 1][j + 1] = ch[p % 26];
          p++;
          k -= 2;
        }
        r += 2;
      }
      for (int j = 1; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            if (l > 0 && v[j][l - 1] == ch[p % 26]) {
              p++;
            }
            if (j > 0 && v[j - 1][l] == ch[p % 26]) p++;
            if (j != n - 1 && v[j + 1][l - 1] == ch[p % 26]) p++;
            if (j < n - 2 && v[j + 2][l] == ch[p % 26]) p++;
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p++;
          }
        }
      }
    } else if (m % 2) {
      int r = 0, p = 0;
      while (k > 0) {
        for (int j = 0; j < m && k > 0; j += 2) {
          if (r > 0 && v[r - 1][j] == ch[p % 26]) p++;
          if (j > 0 && v[r][j - 1] == ch[p % 26]) p++;
          v[r][j] = ch[p % 26];
          v[r][j + 1] = ch[p % 26];
          p++;
          v[r + 1][j] = ch[p % 26];
          v[r + 1][j + 1] = ch[p % 26];
          p++;
          k -= 2;
        }
        r += 2;
      }
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            if (l > 0 && v[j][l - 1] == ch[p % 26]) {
              p++;
            }
            if (j > 0 && v[j - 1][l] == ch[p % 26]) p++;
            if (j != n - 1 && v[j + 1][l - 1] == ch[p % 26]) p++;
            if (j < n - 2 && v[j + 2][l] == ch[p % 26]) p++;
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p++;
          }
        }
      }
    } else {
      int r = 0, p = 0;
      while (k > 0) {
        for (int j = 0; j < m && k > 0; j += 2) {
          if (r > 0 && v[r - 1][j] == ch[p % 26]) p++;
          if (j > 0 && v[r][j - 1] == ch[p % 26]) p++;
          v[r][j] = ch[p % 26];
          v[r][j + 1] = ch[p % 26];
          p++;
          v[r + 1][j] = ch[p % 26];
          v[r + 1][j + 1] = ch[p % 26];
          p++;
          k -= 2;
        }
        r += 2;
      }
      for (int j = 0; j < n; j++) {
        for (int l = 0; l < m; l++) {
          if (v[j][l] == '0') {
            if (l > 0 && v[j][l - 1] == ch[p % 26]) {
              p++;
            }
            if (j > 0 && v[j - 1][l] == ch[p % 26]) p++;
            if (j != n - 1 && v[j + 1][l - 1] == ch[p % 26]) p++;
            if (j < n - 2 && v[j + 2][l] == ch[p % 26]) p++;
            v[j][l] = ch[p % 26];
            v[j + 1][l] = ch[p % 26];
            p++;
          }
        }
      }
    }
    for (int j = 0; j < n; j++) {
      for (int l = 0; l < m; l++) {
        cout << v[j][l];
      }
      cout << endl;
    }
  }
}
