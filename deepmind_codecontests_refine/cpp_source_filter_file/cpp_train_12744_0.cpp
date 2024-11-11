#include <bits/stdc++.h>
using namespace std;
const long long maxn = 5000;
const long long M = 1e9 + 7;
const long long MAXX = 4e18;
long long p, t, z, n, m, l, x, y, maxx, b[maxn];
vector<long long> v[maxn];
string s[maxn];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      if (s[i][j] == '1') {
        z = j, l = 0;
        while (s[i][z] == '1' && z < m) l++, z++;
        for (x = j; x < z; x++) v[x].push_back(l), l--;
        j = z - 1;
      } else
        v[j].push_back(0);
    }
  for (int i = 0; i < m; i++) {
    fill(b, b + maxn, 0), l = 0;
    for (int j = 0; j < n; j++) b[v[i][j]]++;
    for (int j = m; j >= 0; j--) {
      l = l + b[j];
      maxx = max(maxx, l * j);
    }
  }
  cout << maxx;
  return 0;
}
