#include <bits/stdc++.h>
using namespace std;
const int N = 65536;
const int MOD = 1e9 + 7;
struct val {
  int d[N];
  val() { memset(d, 0, sizeof d); }
};
val operator+(val a, val b) {
  for (int i = 0; i < N; ++i) {
    a.d[i] += b.d[i];
    if (a.d[i] >= MOD) a.d[i] -= MOD;
  }
  return a;
}
val operator|(val a, val b) {
  for (int i = 2; i <= N; i <<= 1)
    for (int j = 0; j < N; j += i)
      for (int k = j; k < j + (i >> 1); ++k) {
        a.d[k + (i >> 1)] += a.d[k];
        if (a.d[k + (i >> 1)] >= MOD) a.d[k + (i >> 1)] -= MOD;
        b.d[k + (i >> 1)] += b.d[k];
        if (b.d[k + (i >> 1)] >= MOD) b.d[k + (i >> 1)] -= MOD;
      }
  for (int i = 0; i < N; ++i) a.d[i] = 1ll * a.d[i] * b.d[i] % MOD;
  for (int i = 2; i <= N; i <<= 1)
    for (int j = 0; j < N; j += i)
      for (int k = j; k < j + (i >> 1); ++k) {
        a.d[k + (i >> 1)] -= a.d[k];
        if (a.d[k + (i >> 1)] < 0) a.d[k + (i >> 1)] += MOD;
      }
  return a;
}
val operator&(val a, val b) {
  for (int i = 2; i <= N; i <<= 1)
    for (int j = 0; j < N; j += i)
      for (int k = j; k < j + (i >> 1); ++k) {
        a.d[k] += a.d[k + (i >> 1)];
        if (a.d[k] >= MOD) a.d[k] -= MOD;
        b.d[k] += b.d[k + (i >> 1)];
        if (b.d[k] >= MOD) b.d[k] -= MOD;
      }
  for (int i = 0; i < N; ++i) a.d[i] = 1ll * a.d[i] * b.d[i] % MOD;
  for (int i = 2; i <= N; i <<= 1)
    for (int j = 0; j < N; j += i)
      for (int k = j; k < j + (i >> 1); ++k) {
        a.d[k] -= a.d[k + (i >> 1)];
        if (a.d[k] < 0) a.d[k] += MOD;
      }
  return a;
}
string st;
val solve(int l, int r) {
  if (l == r - 1) {
    val a;
    for (int i = 0; i < 4; ++i) {
      int k1 = 0, k2 = 0;
      for (int j = 0; j < 16; ++j)
        if (j & (1 << i))
          k1 |= 1 << j;
        else
          k2 |= 1 << j;
      if (st[l] == '?' || st[l] == 'A' + i) a.d[k1]++;
      if (st[l] == '?' || st[l] == 'a' + i) a.d[k2]++;
    }
    return a;
  } else {
    int p = 0;
    for (int i = l; i < r; ++i)
      if (st[i] == '(')
        p++;
      else if (st[i] == ')')
        p--;
      else if (p == 0) {
        val a = solve(l + 1, i - 1), b = solve(i + 2, r - 1), c;
        if (st[i] == '|' || st[i] == '?') c = c + (a & b);
        if (st[i] == '&' || st[i] == '?') c = c + (a | b);
        return c;
      }
  }
}
int n, ok[N], res;
int main() {
  cin >> st;
  cin >> n;
  for (int i = 0; i < N; ++i) ok[i] = 1;
  for (int i = 0; i < n; ++i) {
    int p = 0, q;
    for (int j = 0; j < 4; ++j) {
      int k;
      cin >> k;
      p |= k << j;
    }
    cin >> q;
    for (int j = 0; j < N; ++j)
      if (((bool)(j & (1 << p))) ^ q) ok[j] = 0;
  }
  val a = solve(0, st.size());
  for (int i = 0; i < N; ++i) {
    res += ok[i] * a.d[i];
    if (res >= MOD) res -= MOD;
  }
  cout << res << endl;
}
