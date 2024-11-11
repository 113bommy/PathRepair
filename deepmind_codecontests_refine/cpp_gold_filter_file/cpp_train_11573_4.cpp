#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T pow2(T a) {
  return a * a;
}
const int MOD = (int)1e6 + 3;
;
const int maxn = (int)5e5 + 10;
;
long long n, m, p[maxn];
vector<vector<long long> > num, t;
void resize(vector<vector<long long> >& a, long long x, long long y) {
  a.resize(x);
  for (int i = 0; i < x; i++) a[i].resize(y);
}
bool down(int a) { return a == 3 || a == 2; }
bool up(int a) { return a == 1 || a == 4; }
void done() {
  cout << "0";
  exit(0);
}
long long solve() {
  for (int i = 0; i < m; i++) p[i] = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (p[j] == 1 && down(num[i][j])) done();
      if (p[j] == 2 && up(num[i][j])) done();
      if (up(num[i][j])) p[j] = 1;
      if (down(num[i][j])) p[j] = 2;
    }
    for (int i = 0; i < m; i++)
      if (p[i] != 0) p[i] = (p[i] == 1 ? 2 : 1);
  }
  long long ans = 1;
  for (int i = 0; i < m; i++)
    if (p[i] == 0) ans = (ans * 2) % MOD;
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  resize(num, n, m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      num[i][j] = (c == '.' ? 0 : c - '0');
    }
  long long ans = solve();
  resize(t, m, n);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) {
      t[m - j - 1][i] =
          (num[i][j] == 0 ? 0 : (num[i][j] + 1 == 5 ? 1 : num[i][j] + 1));
    }
  resize(num, m, n);
  for (int i = 0; i < m; i++)
    for (int j = 0; j < n; j++) num[i][j] = t[i][j];
  swap(n, m);
  cout << (ans * solve()) % MOD;
}
