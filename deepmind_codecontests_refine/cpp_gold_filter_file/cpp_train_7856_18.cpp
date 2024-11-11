#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
const int M = 1e9;
const int inf = 1e9 + 7;
const long long base = 1e18;
const double pi = acos(-1);
const double ep = 1e-9;
int n, m, k;
string s, t;
string x = "ATGC";
int a[N];
bitset<N> res, val[4];
int main() {
  cin >> n >> m >> k;
  cin >> s >> t;
  for (int tt = (int)0; tt < (int)4; tt++) {
    memset(a, 0, sizeof(a));
    for (int i = (int)0; i < (int)n; i++)
      if (s[i] == x[tt]) {
        int u = max(0, i - k);
        a[u]++;
        u = min(n, i + k + 1);
        a[u]--;
      }
    for (int i = (int)1; i < (int)n; i++) a[i] = a[i] + a[i - 1];
    for (int i = (int)0; i < (int)n; i++) val[tt][i] = (a[i] > 0) ? 1 : 0;
  }
  for (int i = (int)0; i < (int)n; i++) res.set(i);
  for (int i = (int)0; i < (int)m; i++) {
    int j = 0;
    if (t[i] == 'T')
      j = 1;
    else if (t[i] == 'G')
      j = 2;
    else if (t[i] == 'C')
      j = 3;
    res &= val[j] >> i;
  }
  cout << res.count() << endl;
}
