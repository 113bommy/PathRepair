#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 3e6;
long long q;
string s, t, z;
long long m, n, k;
vector<long long> vertex[MAXN];
long long ok = 1;
long long vitri[MAXN];
long long cnt;
long long check[MAXN];
long long po[MAXN];
void dfs(long long x, long long color, long long cnt) {
  po[x] = cnt;
  check[x] = color;
  for (long long i = 0; i < vertex[x].size(); i++) {
    if (check[vertex[x][i]] == 0) {
      dfs(vertex[x][i], 3 - color, cnt++);
    } else {
      if ((po[vertex[x][i]] - po[x]) % 2 == 1) {
        ok = 0;
      }
    }
  }
}
signed main() {
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> s;
  ok = 1;
  for (long long i = 0; i < n; i++) {
    vitri[i] = i;
  }
  for (long long j = 1; j <= 20000; j++) {
    for (long long i = 1; i < n; i++) {
      if (s[i] < s[i - 1]) {
        char x;
        x = s[i];
        s[i] = s[i - 1];
        s[i - 1] = x;
        k = vitri[i];
        vitri[i] = vitri[i - 1];
        vitri[i - 1] = k;
        vertex[vitri[i]].push_back(vitri[i - 1]);
      }
    }
  }
  for (long long i = 0; i < n; i++) {
    if (check[i] == 0) dfs(i, 1, 1);
  }
  if (ok == 0) {
    cout << "NO";
    return 0;
  }
  cout << "YES"
       << "\n";
  for (long long i = 0; i < n; i++) {
    cout << check[i] - 1;
  }
  return 0;
}
