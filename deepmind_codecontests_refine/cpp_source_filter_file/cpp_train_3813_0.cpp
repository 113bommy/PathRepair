#include <bits/stdc++.h>
using namespace std;
const long long M = 998244353;
const long long N = 2e5 + 10;
const long long IM = 1e15 + 37;
const long double PI = 3.1415926535897932384;
inline void PP(long long n) { cout << n << " "; }
void PV(vector<long long> v) {
  for (long long i = 0; i < v.size(); i++) cout << v[i] << " ";
  cout << "\n";
}
void PVV(vector<pair<long long, long long> > v) {
  for (long long i = 0; i < v.size(); i++)
    cout << v[i].first << " " << v[i].second << "\n";
}
void PA(long long v[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cout << v[i] << ' ';
  cout << "\n";
}
void IN(long long a[], long long n, long long x = 0) {
  for (long long i = x; i < n + x; i++) cin >> a[i];
}
inline void op() {}
long long a[100 + 10][100 + 10];
signed main() {
  op();
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, m, k;
  cin >> n >> m >> k;
  for (long long i = 1; i <= n; i++) {
    for (long long j = 1; j <= m; j++) {
      cin >> a[i][j];
      a[i][j] += a[i - 1][j];
    }
  }
  long long x = 0, y = 0;
  for (long long j = 1; j <= m; j++) {
    long long c = 0, u = 0, l;
    long long p = 0, ch = IM;
    for (long long i = 1; i <= n; i++) {
      if (a[i][j] > c) {
        c = a[i][j];
        l = min(k, n - i + 1);
        l = a[i + l - 1][j] - a[i - 1][j];
        if (p < l) {
          p = l;
          ch = u;
        } else if (p == l) {
          ch = min(ch, u);
        }
        u++;
      }
    }
    x += p;
    y += ch;
  }
  cout << x << " " << y << "\n";
  return 0;
}
