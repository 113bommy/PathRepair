#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > mul(vector<vector<long long> > &a,
                               vector<vector<long long> > &b) {
  vector<vector<long long> > c(a.size(), vector<long long>(b[0].size()));
  for (int i = 0; i < a.size(); i++)
    for (int j = 0; j < b.size(); j++)
      for (int k = 0; k < b[0].size(); k++)
        c[i][k] = (c[i][k] + a[i][j] * b[j][k]) % 1000000007;
  return c;
}
vector<vector<long long> > pow(vector<vector<long long> > a, long long t) {
  vector<vector<long long> > b(a.size(), vector<long long>(a.size()));
  for (int i = 0; i < a.size(); i++) b[i][i] = 1ll;
  while (t) {
    if (t & 1) b = mul(b, a);
    a = mul(a, a);
    t >>= 1;
  }
  return b;
}
int n;
long long b, k, x;
long long num[130];
int main() {
  while (cin >> n >> b >> k >> x) {
    for (int i = 0; i < n; i++) {
      long long u;
      cin >> u;
      num[u % x]++;
    }
    vector<vector<long long> > A(x, vector<long long>(x)),
        B(x, vector<long long>(1));
    for (int i = 0; i < x; i++) {
      B[i % x][0] = num[i];
    }
    for (int i = 0; i < x; i++) {
      for (int j = 0; j < x; j++) {
        for (int u = 0; u < x; u++) {
          if ((10 * u + j) % x == i) A[i][j] += num[u];
        }
      }
    }
    A = pow(A, b - 1);
    B = mul(A, B);
    cout << B[k][0] << endl;
  }
  return 0;
}
