#include <bits/stdc++.h>
using namespace std;
template <typename T>
int size(const T& c) {
  return int(c.size());
}
template <typename T>
T sqr(T x) {
  return x * x;
}
long long add(long long x, long long y) {
  return y <= LLONG_MAX - x ? x + y : LLONG_MAX;
}
long long memo[64][64][2][2];
long long solve(int i, int j, int eq0, int eq1, vector<int>& v) {
  if (i > j) return 1;
  long long& res = memo[i][j][eq0][eq1];
  if (res != -1) return res;
  res = 0;
  for (int d1(0), _n(2); d1 < _n; ++d1) {
    if (v[i] != -1 && v[i] != d1) continue;
    int sav1 = v[i];
    v[i] = d1;
    for (int d2(0), _n(2); d2 < _n; ++d2) {
      if (v[j] != -1 && v[j] != d2) continue;
      int sav2 = v[j];
      v[j] = d2;
      bool good = true;
      if (eq0 && v[j] < v[i]) good = false;
      if (eq1 && (v[j] ^ 1) < v[i]) good = false;
      if (good) {
        long long tmp = solve(i + 1, j - 1, int(eq0 && v[j] == v[i]),
                              int(eq1 && (v[j] ^ 1) == v[i]), v);
        res = add(res, tmp);
      }
      v[j] = sav2;
    }
    v[i] = sav1;
  }
  return res;
}
long long amOfEndings(string s, int n) {
  vector<int> v(n);
  for (int i(0), _n(n); i < _n; ++i) v[i] = i < size(s) ? s[i] - '0' : -1;
  memset(memo, -1, sizeof(memo));
  return solve(0, n - 1, 1, 1, v);
}
int main() {
  int n;
  long long k;
  scanf("%d%I64d", &n, &k);
  ++k;
  if (add(amOfEndings("0", n), amOfEndings("1", n)) < k)
    printf("-1\n");
  else {
    string s = "";
    while (size(s) < n) {
      long long t = amOfEndings(s + "0", n);
      if (k <= t) {
        s += "0";
      } else {
        k -= t;
        s += "1";
      }
    }
    assert(k == 1);
    printf("%s\n", s.c_str());
  }
  exit(0);
}
