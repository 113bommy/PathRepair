#include <bits/stdc++.h>
using namespace std;
long long t, n, i, j, k, x, y, z, l, r, mid, ans, mod = 1e9 + 7, g, m;
long long a[400005], b[400005], d[200005][3];
char ch;
string s, st;
vector<long long> v[300005], u;
int main() {
  ios::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  x = 1;
  cin >> n >> s;
  for (i = 0; i < n; i++) {
    if (s[i] == '?') {
      a[2] *= 3;
      a[2] += a[1];
      a[1] *= 3;
      a[1] += a[0];
      a[0] *= 3;
      a[0] += x;
      x *= 3;
    } else if (s[i] == 'a')
      a[0] += x;
    else if (s[i] == 'b')
      a[1] += a[0];
    else
      a[2] += a[1];
    a[0] %= mod;
    a[1] %= mod;
    a[2] %= mod;
    x %= mod;
  }
  cout << a[2];
}
