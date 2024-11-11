#include <bits/stdc++.h>
using namespace std;
const int tam = 100010;
long long MOD = 1000000007;
const int MOD1 = 998244353;
const double DINF = 1e100;
const double EPS = 1e-9;
const double PI = acos(-1);
vector<vector<long long>> ans;
void mult(vector<vector<long long>> m1, vector<vector<long long>> m2) {
  assert(m1[0].size() == m2.size());
  ans.clear();
  long long answer = 0;
  for (int i = 0; i < m1.size(); i++) {
    vector<long long> fila;
    for (int j = 0; j < m2[0].size(); j++) {
      answer = 0;
      for (int k = 0; k < m2.size(); k++)
        answer = (answer + (__int128)m1[i][k] * m2[k][j]) % MOD;
      fila.push_back(answer);
    }
    ans.push_back(fila);
  }
}
void pot(vector<vector<long long>> base, long long exp) {
  vector<vector<long long>> res(base.size(), vector<long long>(base.size(), 0));
  for (int i = 0; i < base.size(); i++) res[i][i] = 1;
  while (exp) {
    if (exp & 1) {
      mult(res, base);
      res = ans;
    }
    mult(base, base);
    base = ans;
    exp /= 2;
  }
  ans = res;
}
long long ar[1000010];
long long pot(long long b, long long e) {
  long long res = 1;
  while (e > 0) {
    if (e & 1) res = (__int128)res * b % MOD;
    b = (__int128)b * b % MOD;
    e /= 2;
  }
  return res;
}
long long div(long long a) {
  if (a == 0) return MOD / 2;
  return a / 2;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  long long x, y;
  long long a, b, c, su = 0;
  cin >> n >> x >> y >> MOD;
  for (int i = 0; i < n; i++) {
    cin >> ar[i];
    su += ar[i];
  }
  if (n == 1) {
    cout << ar[0] << '\n';
  } else {
    MOD *= 4;
    a = ar[0] % MOD, b = ar[n - 2] % MOD, c = ar[n - 1] % MOD;
    if (x == 0) swap(x, y);
    su = ((__int128)pot(3, x) * su % (MOD / 2) -
          (__int128)(a + c) * div(pot(3, x) - 1) % (MOD / 2) + MOD / 2) %
         (MOD / 2);
    MOD /= 2;
    if (y == 0)
      cout << su << '\n';
    else {
      swap(x, y);
      vector<vector<long long>> ma(2, vector<long long>(2));
      ma[0][0] = 1;
      ma[0][1] = 1;
      ma[1][0] = 1;
      pot(ma, y);
      ma = ans;
      c = (__int128)ma[0][0] * c % (MOD / 2) +
          (__int128)ma[1][0] * b % (MOD / 2);
      c %= MOD / 2;
      su = ((__int128)pot(3, x) * su % (MOD / 2) -
            (__int128)(a + c) * div(pot(3, x) - 1) % (MOD / 2) + MOD / 2) %
           (MOD / 2);
      MOD /= 2;
      cout << su << '\n';
    }
  }
  return 0;
}
