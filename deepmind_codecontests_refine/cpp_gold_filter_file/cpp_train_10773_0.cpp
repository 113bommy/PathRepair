#include <bits/stdc++.h>
using namespace std;
string s;
int sid[5500], v[5500], pre[5500], suf[5500], vid[5500], sumid[5500], n;
long long solve(int i, int j) {
  if (i > j) return 0;
  if (i == j) return v[i];
  if (sid[i] == sid[j]) {
    long long p = 1;
    for (int t = i; t <= j; t++) p *= v[t];
    return p;
  }
  return suf[i] + sumid[sid[j] - 1] - sumid[sid[i]] + pre[j];
}
int main() {
  while (cin >> s) {
    n = (((int)s.size()) + 1) / 2;
    int id = 0;
    for (int i = 0; i < ((int)s.size()); i += 2) {
      v[i / 2] = s[i] - '0';
      sid[i / 2] = id;
      if (i + 1 < ((int)s.size()) && s[i + 1] == '+') id++;
    }
    for (int i = (0); i < (n); i++) {
      pre[i] = (i == 0 || sid[i] != sid[i - 1]) ? v[i] : v[i] * pre[i - 1];
      if (i == n - 1 || sid[i] != sid[i + 1]) {
        vid[sid[i]] = pre[i];
        sumid[sid[i]] =
            sid[i] == 0 ? vid[sid[i]] : vid[sid[i]] + sumid[sid[i] - 1];
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      suf[i] = (i == n - 1 || sid[i] != sid[i + 1]) ? v[i] : v[i] * suf[i + 1];
    }
    long long maxi = 0;
    for (int j = (0); j < (n); j++)
      for (int i = (0); i < (j + 1); i++) {
        long long r = solve(i, j);
        int t;
        for (t = i - 1; t >= 0 && sid[t] == sid[i]; t--) r *= v[t];
        int u;
        for (u = j + 1; u < n && sid[u] == sid[j]; u++) r *= v[u];
        if (t >= 0) r += sumid[sid[t]];
        if (u < n) r += sumid[sid[n - 1]] - sumid[sid[u] - 1];
        maxi = max(maxi, r);
      }
    cout << maxi << endl;
  }
  return 0;
}
