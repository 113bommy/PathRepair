#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct total {
  long long c[2][2];
  total() {
    long long i, j;
    for (i = 0; i < 2; i++) {
      for (j = 0; j < 2; j++) {
        c[i][j] = 0;
      }
    }
  }
};
total aa[123456], bb[123456];
long long a[123456], b[123456], c[12][12], d[12][12];
long long n, m;
long long check1() {
  long long i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      if (aa[0].c[i][j] != c[i][j]) return 0;
    }
  }
  return 1;
}
long long check2() {
  long long i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      if (bb[0].c[i][j] != c[i][j]) return 0;
    }
  }
  return 1;
}
long long fact[212345], invfact[212345], inv[123456];
long long precomp() {
  long long i;
  fact[0] = 1;
  for (i = 1; i < 123456; i++) {
    fact[i] = fact[i - 1] * i;
    fact[i] %= (1000 * 1000 * 1000 + 7);
  }
  inv[1] = 1;
  long long p = (1000 * 1000 * 1000 + 7);
  for (i = 2; i < 123456; i++) {
    inv[i] = (p - p / i) * inv[p % i];
    inv[i] %= (1000 * 1000 * 1000 + 7);
  }
  invfact[0] = 1;
  invfact[1] = 1;
  for (i = 2; i < 123456; i++) {
    invfact[i] = invfact[i - 1] * inv[i];
    invfact[i] %= (1000 * 1000 * 1000 + 7);
  }
  return 0;
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r < 0) return 0;
  long long ans = fact[n];
  ans *= invfact[r];
  ans %= (1000 * 1000 * 1000 + 7);
  ans *= invfact[n - r];
  ans %= (1000 * 1000 * 1000 + 7);
  return ans;
}
long long computeans1(long long pos) {
  long long i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      d[i][j] = c[i][j] - aa[pos].c[i][j];
    }
  }
  if (pos != n - 1) {
    d[a[pos + 1]][a[pos] ^ 1]--;
  }
  long long cur = a[pos] ^ 1;
  long long ans = 1;
  if (d[cur][cur ^ 1] == d[cur ^ 1][cur]) {
    ans = nCr(d[cur][cur] + d[cur][cur ^ 1], d[cur][cur ^ 1]);
    if (d[cur][cur ^ 1] >= 1)
      ans *=
          nCr(d[cur ^ 1][cur ^ 1] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
    else if (d[cur ^ 1][cur ^ 1] != 0)
      ans = 0;
  } else if (d[cur][cur ^ 1] == d[cur ^ 1][cur] + 1) {
    ans = nCr(d[0][0] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
    ans *= nCr(d[1][1] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
  } else {
    ans = 0;
  }
  ans %= (1000 * 1000 * 1000 + 7);
  return ans;
}
long long computeans2(long long pos) {
  long long i, j;
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      d[i][j] = c[i][j] - bb[pos + 1].c[i][j];
    }
  }
  if (pos != m - 1) {
    d[b[pos + 1]][b[pos] ^ 1]--;
  }
  long long cur = b[pos] ^ 1;
  long long ans = 1;
  if (d[cur][cur ^ 1] == d[cur ^ 1][cur]) {
    ans = nCr(d[cur][cur] + d[cur][cur ^ 1], d[cur][cur ^ 1]);
    if (d[cur][cur ^ 1] >= 1)
      ans *=
          nCr(d[cur ^ 1][cur ^ 1] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
    else if (d[cur ^ 1][cur ^ 1] != 0)
      ans = 0;
  } else if (d[cur][cur ^ 1] == d[cur ^ 1][cur] + 1) {
    ans = nCr(d[0][0] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
    ans *= nCr(d[1][1] + d[cur][cur ^ 1] - 1, d[cur][cur ^ 1] - 1);
  } else {
    ans = 0;
  }
  ans %= (1000 * 1000 * 1000 + 7);
  return ans;
}
long long visit[123456][2][2], dp[123456][2][2];
long long compute(long long pos, long long f1, long long f2) {
  if (pos == -1) {
    if (f1) {
      return check1();
    } else {
      return check2();
    }
  }
  if (visit[pos][f1][f2] == 1) {
    return dp[pos][f1][f2];
  }
  visit[pos][f1][f2] = 1;
  long long ans = 0;
  long long nodo = 0;
  long long newf1, newf2;
  if (f1) {
    if (a[pos] == 1) {
      nodo = 1;
    } else {
      newf1 = 1;
    }
  } else {
    newf1 = 0;
  }
  if (f2) {
    if (b[pos] == 1) {
      newf2 = 0;
    } else {
      newf2 = 1;
    }
  } else {
    newf2 = 0;
  }
  if (!nodo && pos != m - 1) {
    if (newf1 + newf2) {
      ans += compute(pos - 1, newf1, newf2);
    } else {
      if (f1) {
        ans += computeans1(pos);
      } else {
        ans += computeans2(pos);
      }
    }
  }
  nodo = 0;
  if (f1) {
    if (a[pos] == 1) {
      newf1 = 1;
    } else {
      newf1 = 0;
    }
  } else {
    newf1 = 0;
  }
  if (f2) {
    if (b[pos] == 1) {
      newf2 = 1;
    } else {
      nodo = 1;
    }
  } else {
    newf2 = 0;
  }
  if (!nodo) {
    if (newf1 + newf2) {
      ans += compute(pos - 1, newf1, newf2);
    } else {
      if (f1) {
        ans += computeans1(pos);
      } else {
        ans += computeans2(pos);
      }
    }
  }
  ans %= (1000 * 1000 * 1000 + 7);
  dp[pos][f1][f2] = ans;
  return ans;
}
signed main() {
  std::ios::sync_with_stdio(false);
  cin.tie(NULL);
  long long i, j;
  string s, t;
  long long sumi = 0;
  cin >> s >> t;
  precomp();
  for (i = 0; i < 2; i++) {
    for (j = 0; j < 2; j++) {
      cin >> c[i][j];
      sumi += c[i][j];
    }
  }
  sumi++;
  for (i = 0; i < s.length(); i++) {
    a[s.length() - 1 - i] = s[i] - '0';
  }
  for (i = 0; i < t.length(); i++) {
    b[t.length() - 1 - i] = t[i] - '0';
  }
  n = s.length();
  m = t.length();
  if (sumi < n || m < sumi) {
    cout << 0 << endl;
    return 0;
  }
  if (m > sumi) {
    for (i = 0; i < sumi; i++) {
      b[i] = 1;
    }
    for (i = sumi; i < m; i++) {
      b[i] = 0;
    }
    m = sumi;
  }
  for (i = 0; i < m + 10; i++) {
    aa[i] = total();
    bb[i] = total();
  }
  for (i = n - 2; i >= 0; i--) {
    aa[i] = aa[i + 1];
    aa[i].c[a[i + 1]][a[i]]++;
  }
  for (i = m - 2; i >= 0; i--) {
    bb[i] = bb[i + 1];
    bb[i].c[b[i + 1]][b[i]]++;
  }
  cout << compute(sumi - 1, 1, 1) << endl;
  return 0;
}
