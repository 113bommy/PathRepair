#include <bits/stdc++.h>
using namespace std;
int main() {
  long long i, n, r, S, Z, s1, s2, s3, s4, s5, s6, s7, s8, x, y, z, m, j, l, k,
      t;
  long long a[500045];
  long long b[300045];
  long long c[100001];
  long long d[100001];
  long long e[100001];
  pair<long long, long long> aa[100001];
  double h, w, u, v, uu, vv;
  string q1;
  string q2;
  string q3;
  string q4;
  string s;
  string q;
  string sq[50005];
  string qs[3001];
  map<long long, long long> g;
  map<long long, long long>::iterator it;
  cin >> n >> m >> k;
  x = 0;
  for (i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= n - k; i++) {
    x = x + a[i];
  }
  for (i = 1; i <= k; i++) {
    x = x + k;
  }
  cout << x;
}
