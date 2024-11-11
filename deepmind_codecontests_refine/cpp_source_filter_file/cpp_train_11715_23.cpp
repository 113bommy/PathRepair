#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 6;
const int mod = 1e9 + 7;
int n, pre[105], k;
struct Node {
  int p, id;
  bool operator<(const Node &rhs) const { return p > rhs.p; }
};
priority_queue<Node> q;
struct Matrix {
  long long g[105][105], n, m;
  Matrix() {
    memset(g, 0, sizeof g);
    n = m = 0;
  }
  Matrix operator*(const Matrix &rhs) const {
    Matrix ans;
    ans.n = n, ans.m = rhs.m;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= rhs.m; j++)
        for (int l = 1; l <= m; l++)
          ans.g[i][j] = (ans.g[i][j] + g[i][l] * rhs.g[l][j] % mod) % mod;
    return ans;
  }
} A, B;
long long f[N + N], ans, m;
Matrix ksm(Matrix d, long long z) {
  Matrix res = d;
  z--;
  while (z) {
    if (z & 1) res = res * d;
    d = d * d;
    z >>= 1;
  }
  return res;
}
int main() {
  char s[N];
  scanf("%lld%d", &m, &k);
  scanf("%s", s + 1);
  long long sum = 0;
  n = strlen(s + 1);
  for (int i = 1, x; i <= n; i++) {
    x = s[i] - 'a' + 1;
    pre[x] = i;
    long long tp = f[x];
    f[x] = (sum + 1) % mod;
    sum = (sum + f[x]) % mod;
    sum = (sum - tp + mod) % mod;
  }
  for (int i = 1; i <= k; i++) q.push((Node){pre[i], i});
  if (m >= n) {
    for (long long i = 1; i <= m; i++) {
      if (q.top().p) {
        m -= i - 1;
        break;
      }
      pre[q.top().id] = i + n;
      long long tp = f[q.top().id];
      f[q.top().id] = (sum + 1) % mod;
      sum = (sum + f[q.top().id]) % mod;
      sum = (sum - tp + mod) % mod;
      Node t = q.top();
      q.pop();
      q.push((Node){pre[t.id], t.id});
    }
  } else {
    for (long long i = 1; i <= m; i++) {
      Node t = q.top();
      q.pop();
      pre[t.id] = i + n;
      long long tp = f[t.id];
      f[t.id] = (sum + 1) % mod;
      sum = (sum + f[t.id]) % mod;
      sum = (sum - tp + mod) % mod;
      q.push((Node){pre[t.id], t.id});
    }
    cout << sum + 1 << endl;
    return 0;
  }
  A.g[1][1] = B.g[1][1] = 1;
  B.n = 1, B.m = A.n = A.m = k + 1;
  for (int i = 2; i <= k; i++) A.g[i + 1][i] = 1;
  for (int i = 1; i <= k + 1; i++) A.g[i][k + 1] = 1;
  for (int i = 2; i <= k + 1; i++) B.g[1][i] = f[q.top().id], q.pop();
  A = ksm(A, m + 1);
  B = B * A;
  cout << B.g[1][k + 1];
}
