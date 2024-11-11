#include <bits/stdc++.h>
using namespace std;
const int mx = (int)1e6 + 2;
int lo[mx], fact[3][mx];
vector<int> pr, po;
long long int ppow(int x, int e) {
  if (e == 0) return 1;
  if (e == 1) return x;
  long long int root = pow(x, e / 2);
  root *= root;
  if ((e & 1)) root *= x;
  return root;
}
int recur(long long int n, int ind, long long int sofar) {
  if (sofar > n) return 0;
  if (ind == pr.size()) {
    if (sofar <= n) return 1;
    return 0;
  }
  int ret = 0;
  int i = 0;
  long long int x = 1;
  for (; i <= po[ind]; i++) {
    if (sofar > (long)2e18 / x) break;
    ret += recur(n, ind + 1, sofar * x);
    x *= pr[ind];
  }
  return ret;
}
int main() {
  int i, j, k, l, p, q, c;
  long long int a, b, ans = 0, n, m, s;
  for (i = 1; i < mx; i++) lo[i] = i;
  for (j = 2; j < mx; j++) {
    if (lo[j] == j) {
      for (i = 2 * j; i < mx; i += j) lo[i] = min(lo[i], j);
    }
  }
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> l;
  while (l--) {
    int nums[3][3];
    for (i = 0; i < 3; i++)
      for (j = 0; j < 3; j++) cin >> nums[i][j];
    set<int> primes[3];
    for (j = 0; j < 3; j++) {
      for (i = 0; i < 3; i++) {
        c = nums[j][i];
        while (lo[c] > 1) {
          k = lo[c];
          p = 0;
          while (k == lo[c]) {
            c /= lo[c];
            p++;
          }
          primes[j].insert(k);
          fact[j][k] += p;
        }
      }
    }
    pr.clear();
    po.clear();
    primes[2].insert(2);
    fact[2][2]++;
    for (int x : primes[2]) {
      pr.emplace_back(x);
      po.emplace_back(fact[2][x]);
    }
    n = (long long int)nums[0][0] * (long long int)nums[0][1] * nums[0][2];
    m = (long long int)nums[1][0] * (long long int)nums[1][1] * nums[1][2];
    ans = recur(n, 0, 1);
    vector<long long int> bad;
    for (int x : primes[0]) {
      if (fact[0][x] > fact[2][x]) {
        b = ppow(x, fact[2][x] + 1);
        bad.push_back(b);
      }
    }
    int sgn = +1;
    int limit = 1 << bad.size();
    for (i = 0; i < limit; i++, sgn *= -1) {
      int conf = (i ^ (i >> 1));
      long long int act = 1;
      for (j = 0; j < bad.size(); j++)
        if ((conf & (1 << j)) > 0) act = min(m + 1, act * bad[j]);
      ans += sgn * m / act;
    }
    cout << ans << '\n';
    for (j = 0; j < 3; j++) {
      for (int x : primes[j]) fact[j][x] = 0;
    }
  }
  return 0;
}
