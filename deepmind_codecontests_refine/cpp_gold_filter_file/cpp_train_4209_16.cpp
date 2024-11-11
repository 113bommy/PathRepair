#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, r, S, Z, s1, s2, s3, s4, s5, s6, s7, s8, x, y, z, m, j, l, k,
      t;
  long long a[200045];
  long long b[200045];
  long long c[100001];
  long long d[100001];
  long long e[1000001];
  pair<long long, long long> aa[100001];
  double w, u, v, uu, vv;
  string q1;
  string q2;
  string q3;
  string q4;
  string s;
  string sq[3001];
  string qs[3001];
  map<long long, long long> g;
  map<long long, long long>::iterator it;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  t = n / m;
  for (i = 1; i <= m; i++) {
    x = 0;
    y = 0;
    for (j = i; j <= n; j = j + m) {
      if (a[j] == 1)
        x++;
      else
        y++;
    }
    k = k + min(x, y);
  }
  cout << k;
}
