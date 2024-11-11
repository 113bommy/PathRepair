#include <bits/stdc++.h>
using namespace std;
long long m, l, r, k;
const int n = 2;
vector<vector<long long> > mult(vector<vector<long long> > one,
                                vector<vector<long long> > two) {
  vector<vector<long long> > ret(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      ret[i][j] = 0;
      for (int k = 0; k < n; k++) {
        ret[i][j] += (one[i][k] * two[k][j]) % m;
        ret[i][j] %= m;
      }
    }
  return ret;
}
vector<vector<long long> > iden() {
  vector<vector<long long> > ret(n, vector<long long>(n, 0));
  for (int i = 0; i < n; i++) ret[i][i] = 1;
  return ret;
}
vector<vector<long long> > sim() {
  vector<vector<long long> > ret(n, vector<long long>(n, 1));
  ret[0][0] = 0;
  return ret;
}
vector<vector<long long> > enpow(long long n) {
  if (n == 0) return iden();
  if (n == 1) return sim();
  vector<vector<long long> > ret = enpow(n / 2);
  ret = mult(ret, ret);
  if (n % 2 == 1) ret = mult(ret, sim());
  return ret;
}
long long howMuch(long long d) {
  long long x, y, r1, l1;
  long long ret;
  x = r / d;
  r1 = x * d;
  y = l / d;
  l1 = y * d;
  if (l1 < l) l1 += d;
  if (l1 > r1)
    ret = 0;
  else
    ret = (r1 - l1) / d + 1ll;
  return ret;
}
void oku() {
  cin >> m >> l >> r >> k;
  long long best = 0;
  long long x, y, i, j, t, w, temp, p, q, d, r1, l1, c1, c2;
  for (d = 1ll; d * d <= r; d++) {
    c1 = howMuch(d);
    if (c1 >= k) best = max(best, d);
    x = r / d;
    c2 = howMuch(x);
    if (c2 >= k) best = max(best, x);
  }
  vector<vector<long long> > ret = enpow(best);
  cout << (ret[0][1] % m);
}
int main() {
  oku();
  return 0;
}
