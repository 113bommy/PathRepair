#include <bits/stdc++.h>
const long double pie = 3.1415926535;
using namespace std;
long long fpow(long long n, long long p) {
  long long m = 1;
  while (p) {
    if (p % 2) m *= n;
    p >>= 1;
    n *= n;
  }
  return m;
}
bool br1, br2, br;
char ch, ch1, ch2;
long long n, k, x, y, z, mini, maxi, l, ind, ini, sum, t, len, r, w, imini, m;
string s, s1, s2;
long long a[(int)1e5 + 10];
void solve() {
  cin >> n >> m >> k;
  for (long long i = 0; i < n; i++)
    for (long long j = 0; j < m; j++) {
      cin >> ch;
      if (ch == 'U' && i % 2 == 0) a[j]++;
      if (ch == 'L' && j >= i) a[j - i]++;
      if (ch == 'R' && j + i < m) a[i + j]++;
    }
  for (long long i = 0; i < m; i++) cout << a[i] << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  solve();
  return 0;
}
