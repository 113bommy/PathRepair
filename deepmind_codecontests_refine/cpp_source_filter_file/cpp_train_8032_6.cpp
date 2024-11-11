#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
long long Bpow(long long a, long long s) {
  if (s == 0) {
    return 1;
  }
  long long u = Bpow(a, s / 2);
  if (s & 1)
    return u * u % mod * a % mod;
  else
    return u * u % mod;
}
int main() {
  int n, m;
  cin >> n >> m;
  vector<vector<char>> a(n, vector<char>(m));
  vector<int> vert, gor;
  vector<int> hv(501), hg(501);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      if (a[i][j] == '*') {
        if (!hv[i]) vert.push_back(i);
        hv[i]++;
        if (!hg[j]) gor.push_back(j);
        hg[j]++;
      }
    }
  }
  int v = -1;
  for (auto& t : vert) {
    if (hv[t] > 1) {
      if (v == -1)
        v = t;
      else {
        cout << "NO";
        return 0;
      }
    }
  }
  int g = -1;
  for (auto& t : vert) {
    if (hg[t] > 1) {
      if (g == -1)
        g = t;
      else {
        cout << "NO";
        return 0;
      }
    }
  }
  int firv = 1e9, lastv = 0;
  if (v == -1 || g == -1) {
    cout << "NO";
    return 0;
  }
  for (int i = 0; i < m; i++) {
    if (a[v][i] == '*') {
      firv = min(firv, i);
      lastv = i;
    }
  }
  int firg = 1e9, lastg = 0;
  for (int i = 0; i < n; i++) {
    if (a[i][g] == '*') {
      firg = min(firg, i);
      lastg = i;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '*' && !(i == v || j == g)) {
        cout << "NO";
        return 0;
      }
    }
  }
  if (firv < g && g < lastv && firg < v && v < lastg &&
      lastv - firv + 1 == hv[v] && lastg - firg + 1 == hg[g])
    cout << "YES";
  else
    cout << "NO";
}
