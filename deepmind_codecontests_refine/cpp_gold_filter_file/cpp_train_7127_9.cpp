#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:640000000")
using namespace std;
int a[100][100];
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int toNum(char ch) {
  if (ch >= 'a' && ch <= 'z')
    return ch - 'a';
  else
    return ('z' - 'a' + 1) + ch - 'A';
}
char toChar(int i) {
  if (i <= 'z' - 'a') return i + 'a';
  return 'A' + i - 'z' + 'a' - 1;
}
void inc(char &ch) {
  if (ch == 'z') {
    ch = 'A';
    return;
  } else
    ++ch;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  string s, ss;
  cin >> s >> ss;
  memset(a, 0, sizeof(a));
  for (int _n((n)-1), i(0); i <= _n; ++i)
    a[toNum(s[i]) + 1][toNum(ss[i]) + 1]--;
  int m;
  n = m = k;
  vector<int> u(n + 1), v(m + 1), p(m + 1), way(m + 1);
  for (int i = 1; i <= n; ++i) {
    p[0] = i;
    int j0 = 0;
    vector<int> minv(m + 1, 1000000000);
    vector<char> used(m + 1, false);
    do {
      used[j0] = true;
      int i0 = p[j0], delta = 1000000000, j1;
      for (int j = 1; j <= m; ++j)
        if (!used[j]) {
          int cur = a[i0][j] - u[i0] - v[j];
          if (cur < minv[j]) minv[j] = cur, way[j] = j0;
          if (minv[j] < delta) delta = minv[j], j1 = j;
        }
      for (int j = 0; j <= m; ++j)
        if (used[j])
          u[p[j]] += delta, v[j] -= delta;
        else
          minv[j] -= delta;
      j0 = j1;
    } while (p[j0] != 0);
    do {
      int j1 = way[j0];
      p[j0] = p[j1];
      j0 = j1;
    } while (j0);
  }
  vector<int> ans(n + 1);
  for (int j = 1; j <= m; ++j) ans[p[j]] = j;
  cout << v[0] << endl;
  for (int _n((n)-1), i(0); i <= _n; ++i) cout << toChar(ans[i + 1] - 1);
  cout << endl;
  return 0;
}
