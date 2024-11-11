#include <bits/stdc++.h>
using namespace std;
const int M = 1000000007;
int main() {
  long long n, a, b, c, i, j, k, p, q, r, mi = M;
  cin >> n;
  string x, y, z;
  map<string, long long> mp;
  mp["Anka"] = 0;
  mp["Chapay"] = 1;
  mp["Cleo"] = 2;
  mp["Troll"] = 3;
  mp["Dracul"] = 4;
  mp["Snowy"] = 5;
  mp["Hexadecimal"] = 6;
  vector<long long> g[7], v;
  for (i = 0; i < 7; i++) v.push_back(i);
  for (i = 0; i < n; i++) {
    cin >> x >> y >> z;
    g[mp[x]].push_back(mp[z]);
  }
  cin >> a >> b >> c;
  for (i = 1; i <= 5; i++)
    for (j = 1; j + i <= 6; j++) {
      k = 7 - i - j;
      if (max(a / i, max(b / j, c / k)) - min(a / i, min(b / j, c / k)) <= mi) {
        mi = max(a / i, max(b / j, c / k)) - min(a / i, min(b / j, c / k));
        p = i;
        q = j;
        r = k;
      }
    }
  long long s, sm = 0;
  map<long long, long long> T;
  while (next_permutation(v.begin(), v.end())) {
    s = 0;
    for (i = 0; i < p; i++) T[v[i]] = 1;
    for (i = p; i < p + q; i++) T[v[i]] = 2;
    for (i = p + q; i < p + q + r; i++) T[v[i]] = 3;
    for (i = 0; i < 7; i++)
      for (j = 0; j < g[i].size(); j++)
        if (T[i] == T[g[i][j]]) s++;
    if (s > sm) sm = s;
  }
  cout << mi << ' ' << sm << endl;
}
