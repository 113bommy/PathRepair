#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
struct matrix {
  long long a[3][3];
};
matrix product(matrix &A, matrix &B) {
  matrix res;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) res.a[i][j] = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      for (int l = 0; l < 3; l++) {
        res.a[i][j] = (res.a[i][j] + A.a[i][l] * B.a[l][j]) % MOD;
      }
    }
  }
  return res;
}
matrix matpow(matrix &A, int n) {
  matrix res;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) res.a[i][j] = 0;
  for (int i = 0; i < 3; i++) res.a[i][i] = 1;
  while (n > 0) {
    if (n % 2) res = product(res, A);
    A = product(A, A);
    n /= 2;
  }
  return res;
}
int c[3];
pair<long long, long long> p[3][10005];
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    long long a, l, r;
    cin >> a >> l >> r;
    a--;
    r++;
    p[a][c[a]] = pair<long long, long long>(l, r);
    c[a]++;
  }
  for (int i = 0; i < 3; i++) sort(p[i], p[i] + c[i]);
  map<long long, vector<int>> mp;
  mp[m].push_back(0);
  for (int i = 0; i < 3; i++) {
    long long r = -1;
    if (c[i]) {
      mp[p[i][0].first].push_back(i + 1);
      r = p[i][0].second;
    }
    for (int j = 1; j < c[i]; j++) {
      if (p[i][j].first > r) {
        mp[p[i][j].first].push_back(i + 1);
        mp[r].push_back(-(i + 1));
      }
      r = max(r, p[i][j].second);
    }
    if (r >= 0) mp[r].push_back(-(i + 1));
  }
  int now = 0;
  matrix A;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) A.a[i][j] = 1;
  A.a[2][0] = A.a[0][2] = 0;
  long long d[3];
  d[0] = 0, d[1] = 1, d[2] = 0;
  long long last = 1;
  for (auto itr = mp.begin(); itr != mp.end(); itr++) {
    long long nd[3]{0};
    A = matpow(A, itr->first - last - 1);
    last = itr->first;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) nd[i] = (nd[i] + A.a[i][j] * d[j]) % MOD;
    }
    for (int a : itr->second) {
      if (a < 0) {
        a = abs(a) - 1;
        now &= (7 - (1 << a));
      } else if (a > 0) {
        a = a - 1;
        now |= (1 << a);
      }
    }
    d[0] = (nd[0] + nd[1]) % MOD;
    d[1] = (nd[0] + nd[1] + nd[2]) % MOD;
    d[2] = (nd[1] + nd[2]) % MOD;
    for (int i = 0; i < 3; i++)
      if ((now >> i) & 1) d[i] = 0;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (((now >> i) & 1) | ((now >> j) & 1))
          A.a[i][j] = 0;
        else
          A.a[i][j] = 1;
      }
    A.a[2][0] = A.a[0][2] = 0;
  }
  cout << d[1] << endl;
}
