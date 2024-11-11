#include <bits/stdc++.h>
using namespace std;
int proof(string &a, vector<char> &b) {
  int cnt = 0;
  for (int i = 0; i < a.size(); ++i) {
    if (a[i] != b[i]) cnt++;
  }
  return cnt;
}
int main() {
  bool juego = 0;
  string a, b;
  int n, m, pares = 0, impares = 0, rpta;
  cin >> n >> m;
  vector<char> ans(n);
  for (int i = 0; i < n; ++i) {
    ans[i] = '$';
  }
  vector<char> qp, qimp;
  vector<int> p, imp;
  cin >> a >> b;
  for (int i = 0; i < n; ++i) {
    if (a[i] == b[i]) {
      pares++;
      p.push_back(i);
      qp.push_back(a[i]);
    } else {
      impares++;
      imp.push_back(i);
      if (juego == 0) {
        qimp.push_back(a[i]);
        juego = 1;
      } else {
        qimp.push_back(b[i]);
        juego = 0;
      }
    }
  }
  rpta = pares + impares / 2;
  if (rpta < n - m) {
    cout << -1 << "\n";
    return 0;
  } else {
    int cnti = impares / 2, cntt = 0, llegar = n - m;
    for (int i = 0; i < p.size() and cntt != llegar; ++i) {
      ans[p[i]] = qp[i];
      cntt++;
    }
    for (int i = 0; i < imp.size() and cntt != llegar; i += 2) {
      if (i + 1 < n) {
        ans[imp[i]] = qimp[i];
        ans[imp[i + 1]] = qimp[i + 1];
      }
      cntt++;
    }
    for (int i = 0; i < n; ++i) {
      if (ans[i] == '$') {
        for (int j = 0; j < 26; ++j) {
          if (char(j + 'a') != a[i] and char(j + 'a') != b[i]) {
            ans[i] = char(j + 'a');
            break;
          }
        }
      }
    }
    if (proof(a, ans) == m and proof(b, ans) == m) {
      for (int i = 0; i < n; ++i) cout << ans[i];
      cout << "\n";
    } else
      cout << -1 << "\n";
  }
  return 0;
}
