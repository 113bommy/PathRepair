#include <bits/stdc++.h>
using namespace std;
vector<int> P[500010];
int NUM[200010];
bool U[200010];
int Q[500010];
int Y[500010];
void init() {
  bool sieve[500010];
  memset(sieve, 0, sizeof(sieve));
  int i, j, k, x, y, z, n, m;
  for (i = 2; i < 500010; i++) {
    if (sieve[i] == 0) {
      for (j = i; j < 500010; j += i) {
        P[j].push_back(i);
        sieve[j] = 1;
      }
    }
  }
  for (i = 1; i < 500010; i++) {
    vector<int> tmp = P[i];
    P[i].clear();
    k = tmp.size();
    for (j = 0; j < (1 << k); j++) {
      x = 1;
      z = 0;
      for (n = 0; n < k; n++) {
        if (((j >> n) & 1) == 1) {
          z++;
          x *= tmp[n];
        }
      }
      if ((z % 2) == 1) {
        Y[x] = -1;
      } else {
        Y[x] = 1;
      }
      P[i].push_back(x);
    }
  }
  return;
}
long long solve(int n, int m, long long z) {
  long long x = n;
  long long y = m;
  long long ans = (y * (y - 1) / 2 - x * (x - 1) / 2);
  ans *= z;
  return ans;
}
int main() {
  init();
  int n, q, i, j, k, x;
  scanf("%d%d", &n, &q);
  for (i = 1; i <= n; i++) {
    scanf("%d", &NUM[i]);
  }
  memset(U, 0, sizeof(U));
  memset(Q, 0, sizeof(Q));
  long long res = 0;
  while (q > 0) {
    q--;
    scanf("%d", &x);
    x = NUM[x];
    if (U[x] == 0) {
      U[x] = 1;
      for (i = 0; i < P[x].size(); i++) {
        j = P[x][i];
        n = Q[j];
        res += solve(n, n + 1, Y[j]);
        Q[j]++;
      }
    } else {
      U[x] = 0;
      for (i = 0; i < P[x].size(); i++) {
        j = P[x][i];
        n = Q[j];
        res -= solve(n - 1, n, Y[j]);
        Q[j]--;
      }
    }
    cout << res << endl;
  }
  return 0;
}
