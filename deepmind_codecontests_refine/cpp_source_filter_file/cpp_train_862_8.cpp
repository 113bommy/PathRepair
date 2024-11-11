#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
const double eps = 1e-9;
const double pi = acos(-1.0);
const long long MOD = (long long)1e9 + 7;
long long d[777][777][3][3];
string s;
int n;
int adj(int a, int b) { return a == 0 || b == 0 || a != b; }
long long go(int l, int r, int ll, int rr) {
  if (r <= l) return adj(ll, rr);
  if (d[l][r][ll][rr] != -1) return d[l][r][ll][rr];
  int t = 0;
  int q;
  for (q = l; q <= r; q++)
    if (s[q] == '(')
      t++;
    else {
      t--;
      if (t == 0) break;
    }
  long long res = 0;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      if (i != 0 && j != 0) continue;
      if (i == 0 && j == 0) continue;
      if (!adj(i, ll)) continue;
      res = (res + (go(l + 1, q - 1, i, j) * go(q + 1, r, j, rr) % MOD) % MOD);
    }
  return d[l][r][ll][rr] = res;
}
int main() {
  memset(d, -1, sizeof(d));
  cin >> s;
  n = (int)(s).size();
  cout << go(0, n - 1, 0, 0) << endl;
  return 0;
}
