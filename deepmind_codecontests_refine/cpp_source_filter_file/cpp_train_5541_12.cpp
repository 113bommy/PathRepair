#include <bits/stdc++.h>
using namespace std;
const int MaxN = 1e5 + 17;
const int INF = 1e9 + 17;
int a[MaxN], b[MaxN], n, m, k;
string s;
map<string, int> ma;
int Sumx, Sumy;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= m; ++i) {
    cin >> s;
    if (!ma[s])
      ma[s] = i, ++k, b[k] = 1;
    else
      b[ma[s]]++;
  }
  sort(b + 1, b + k + 1);
  reverse(b + 1, b + k + 1);
  for (int i = 1; i <= k; ++i) Sumx += a[i] * b[i];
  reverse(a + 1, a + n + 1);
  for (int i = 1; i <= k; ++i) Sumy += a[i] * b[i];
  cout << Sumx << ' ' << Sumy << endl;
  return 0;
}
