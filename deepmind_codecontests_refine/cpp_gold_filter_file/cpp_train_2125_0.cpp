#include <bits/stdc++.h>
using namespace std;
using i64 = long long int;
using ii = pair<int, int>;
using ii64 = pair<i64, i64>;
string a, b, v;
int table[105][105][105];
int ta[105][105][105];
int tb[105][105][105];
int tv[105][105][105];
bool ok[105][105][105];
int pi[105];
int solve(int ai, int bi, int vi) {
  if (vi == v.size()) return -987654321;
  if (ai == a.size() || bi == b.size()) return 0;
  if (table[ai][bi][vi] != -1) return table[ai][bi][vi];
  int& res = table[ai][bi][vi];
  res = 0;
  int aup = solve(ai + 1, bi, vi);
  int bup = solve(ai, bi + 1, vi);
  if (aup > bup) {
    res = aup;
    ta[ai][bi][vi] = ai + 1;
    tb[ai][bi][vi] = bi;
    tv[ai][bi][vi] = vi;
  } else {
    res = bup;
    ta[ai][bi][vi] = ai;
    tb[ai][bi][vi] = bi + 1;
    tv[ai][bi][vi] = vi;
  }
  if (a[ai] == b[bi]) {
    int nvi = vi;
    while (nvi > 0 && v[nvi] != a[ai]) nvi = pi[nvi - 1];
    if (a[ai] == v[nvi]) nvi++;
    int select = 1 + solve(ai + 1, bi + 1, nvi);
    if (select > res) {
      res = select;
      ta[ai][bi][vi] = ai + 1;
      tb[ai][bi][vi] = bi + 1;
      tv[ai][bi][vi] = nvi;
      ok[ai][bi][vi] = true;
    }
  }
  return res;
}
int main() {
  cin >> a >> b >> v;
  int j = 0;
  for (int i = 1; i < v.size(); i++) {
    while (j > 0 && v[i] != v[j]) j = pi[j - 1];
    if (v[i] == v[j]) pi[i] = ++j;
  }
  memset(table, -1, sizeof(table));
  int maxLen = solve(0, 0, 0);
  if (maxLen == 0) {
    printf("0\n");
    return 0;
  }
  int ai = 0, bi = 0, vi = 0;
  while (maxLen > 0) {
    if (ok[ai][bi][vi]) {
      printf("%c", a[ai]);
      maxLen--;
    }
    int nai = ta[ai][bi][vi];
    int nbi = tb[ai][bi][vi];
    int nvi = tv[ai][bi][vi];
    ai = nai;
    bi = nbi;
    vi = nvi;
  }
  return 0;
}
