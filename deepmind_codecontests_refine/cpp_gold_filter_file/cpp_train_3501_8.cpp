#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
const long long INF = 1e18 + 7;
const double eps = 1e-9;
int n, a[MAXN], m;
string s;
string d[MAXN], f[MAXN];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m;
  cin >> s;
  for (int i = 1; i <= m; i++) {
    int l = 0, r = 0;
    char c1, c2;
    cin >> l >> r >> c1 >> c2;
    for (int j = l - 1; j < r; j++) {
      if (s[j] == c1) s[j] = c2;
    }
  }
  cout << s;
  return 0;
}
