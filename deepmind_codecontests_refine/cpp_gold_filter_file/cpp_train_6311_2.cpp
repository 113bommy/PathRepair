#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 100, inf = 1e9 + 100, mod = 1e9 + 7, sq = 300;
int n;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cout << n + n / 2 << '\n';
  for (int i = 2; i <= n; i += 2) cout << i << ' ';
  for (int i = 1; i <= n; i += 2) cout << i << ' ';
  for (int i = 2; i <= n; i += 2) cout << i << ' ';
}
