#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > u(vector<vector<long long> > a,
                             vector<vector<long long> > b) {
  vector<vector<long long> > c(2, vector<long long>(2, 0));
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++)
      for (int k = 0; k < 2; k++) {
        c[i][j] += a[i][k] * b[k][j];
        c[i][j] %= 1000000007;
      }
  return c;
}
vector<vector<long long> > binpow(vector<vector<long long> > a, long long n) {
  vector<vector<long long> > c(2, vector<long long>(2, 0));
  if (n == 0) {
    c[0][0] = 1;
    c[0][1] = 0;
    c[1][1] = 1;
    c[1][0] = 0;
    return c;
  }
  if (n % 2 == 1)
    return u(binpow(a, n - 1), a);
  else {
    vector<vector<long long> > b = binpow(a, n / 2);
    return u(b, b);
  }
}
int main() {
  long long n;
  cin >> n;
  vector<vector<long long> > a(2, vector<long long>(2, 0));
  a[0][0] = 3;
  a[0][1] = 1;
  a[1][0] = 1;
  a[1][1] = 3;
  vector<vector<long long> > c = binpow(a, n);
  cout << c[0][0] % 1000000007 << endl;
  return 0;
}
