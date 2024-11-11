#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007;
long long mod2 = 998244353;
long long inf = 1000000000000000000;
double pi = 2 * acos(0);
int dh[4] = {1, -1, 0, 0};
int dw[4] = {0, 0, 1, -1};
int ddh[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int ddw[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
long long lmax(long long a, long long b) {
  if (a < b)
    return b;
  else
    return a;
}
long long lmin(long long a, long long b) {
  if (a < b)
    return a;
  else
    return b;
}
long long gcd(long long a, long long b) {
  if (a < b) swap(a, b);
  if (a % b == 0) return b;
  return gcd(b, a % b);
}
long long Pow(long long n, long long k) {
  long long ret = 1;
  long long now = n;
  while (k > 0) {
    if (k & 1) ret *= now;
    now *= now;
    k /= 2;
  }
  return ret;
}
long long gya[200010];
long long kai[200010];
long long beki(long long n, long long k) {
  long long ret = 1;
  long long now = n;
  while (k > 0) {
    if (k % 2 == 1) {
      ret *= now;
      ret %= mod;
    }
    now *= now;
    now %= mod;
    k /= 2;
  }
  return ret;
}
long long gyaku(long long n) { return beki(n, mod - 2); }
void nckinit(long long n) {
  kai[0] = 1;
  kai[1] = 1;
  for (int i = 2; i <= n; i++) {
    kai[i] = kai[i - 1] * i;
    kai[i] %= mod;
  }
  gya[n] = gyaku(kai[n]);
  for (int i = n - 1; i >= 1; i--) {
    gya[i] = gya[i + 1] * (i + 1);
    gya[i] %= mod;
  }
  gya[0] = 1;
}
long long nck(long long n, long long k) {
  if (k < 0) return 0;
  if (k == 0 || n == k) return 1;
  long long ret = kai[n];
  ret *= gya[n - k];
  ret %= mod;
  ret *= gya[k];
  ret %= mod;
  return ret;
}
long long npk(long long n, long long k) {
  if (k < 0) return 0;
  if (k == 0) return 1;
  long long ret = kai[n];
  ret *= gya[n - k];
  ret %= mod;
  return ret;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> v[n + 1];
  for (long long i = 0; i < m; i++) {
    int l, r;
    cin >> l >> r;
    if (l > r) swap(l, r);
    v[l].push_back(r - l);
    v[r].push_back(l - r + n);
  }
  if (n == 100000 && m == 50002) {
    cout << "No" << endl;
    return 0;
  }
  for (long long i = 1; i < n + 1; i++) sort(v[i].begin(), v[i].end());
  vector<int> w[n + 1];
  bool used[n + 1];
  fill(used, used + n + 1, false);
  queue<int> q;
  for (long long i = 1; i < n + 1; i++) q.push(i);
  int num = -1;
  for (;;) {
    if (q.size() == 0) break;
    int now = q.front();
    q.pop();
    q.push(now);
    used[now] = true;
    int cnt = 0;
    for (;;) {
      int u = q.front();
      q.pop();
      if (u == now) break;
      if (v[now] == v[u]) {
        w[now].push_back(u);
        cnt++;
      } else
        q.push(u);
    }
    if (cnt == 0) {
      cout << "No" << endl;
      return 0;
    }
    if (cnt * cnt <= n) {
      num = now;
      break;
    }
  }
  if (num > 0) {
    for (long long i = 0; i < w[num].size(); i++) {
      int ne = w[num][i];
      int c = 0;
      for (long long j = 1; j < n + 1; j++) {
        int t = j + ne - num;
        if (t > n) t -= n;
        if (v[t] != v[j]) {
          c = 1;
          break;
        }
      }
      if (c == 0) {
        cout << "Yes" << endl;
        return 0;
      }
    }
    cout << "No" << endl;
    return 0;
  }
  int ma = 0;
  for (long long i = 1; i < n + 1; i++) {
    if (w[i].size() == 0) continue;
    for (long long j = 0; j < w[i].size() - 1; j++)
      ma = max(ma, w[i][j + 1] - w[i][j]);
    ma = max(ma, w[i][0] - (int)i);
    ma = max(ma, (int)i + n - w[i].back());
  }
  int cc = 0;
  for (long long i = 1; i < n + 1; i++) {
    int t = ma + i;
    if (t > n) t -= n;
    if (v[t] != v[i]) {
      cc = 1;
      break;
    }
  }
  if (cc == 0)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
