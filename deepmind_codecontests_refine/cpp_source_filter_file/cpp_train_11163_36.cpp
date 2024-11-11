#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX = 2e5 + 5;
const long long MAX2 = 11;
const long long MOD = 998244353;
const long long MOD2 = 1000000006;
const long long INF = 2e18;
const int dr[] = {1, 0, -1, 0, 1, 1, -1, -1, 0};
const int dc[] = {0, 1, 0, -1, 1, -1, 1, -1, 0};
const double pi = acos(-1);
const double EPS = 1e-9;
const int block = 316;
int n, q, push_front[MAX], le[MAX], ri[MAX], l[MAX], r[MAX], cl[MAX], jlh[MAX],
    cnt, a, b, len, id, ls;
long long hs[MAX], x[MAX], key, tmp, pj, t2;
bool z[MAX], st;
char c;
pair<long long, int> res;
inline pair<long long, int> f(int a, int b) {
  if (a > b) return {0, 0};
  int len = b - a + 1;
  return {x[b] - x[a - 1] * hs[len], len};
}
inline pair<long long, int> comp(int a, int b) {
  tmp = pj = st = 0;
  if (z[a]) {
    if (ri[a] - a + 1 & 1) ++pj;
    a = ri[a] + 1;
  }
  if (z[b]) {
    if (b - le[b] + 1 & 1) st = 1;
    b = le[b] - 1;
  }
  if (cl[a] == cl[b]) {
    tmp = l[a] + r[b] - jlh[cl[a]];
    if (st) tmp *= key;
    return {tmp, 1 + pj + st};
  }
  res = f(cl[a] + 1, cl[b] - 1);
  tmp = (l[a] * hs[res.second] + res.first) * key + r[b];
  if (st) tmp *= key;
  return {tmp, cl[b] - cl[a] + 1 + pj + st};
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  key = 998244353;
  cin >> n;
  hs[0] = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> c, z[i] = (c == '1'), push_front[i] = push_front[i - 1] + z[i],
              hs[i] = hs[i - 1] * key;
    if (z[i]) {
      st ^= 1;
      if (le[i - 1])
        le[i] = le[i - 1];
      else
        le[i] = i;
    } else {
      if (st) {
        jlh[id] = cnt;
        x[id] = x[id - 1] * key + cnt;
        st = cnt = 0;
      }
      if (cnt == 0) ++id;
      ++cnt, r[i] = cnt;
      cl[i] = id;
    }
  }
  if (cnt) x[id] = x[id - 1] * key + cnt, jlh[id] = cnt;
  ls = id;
  cnt = 0;
  for (int i = n; i >= 1; --i) {
    if (z[i]) {
      if (ri[i + 1])
        ri[i] = ri[i + 1];
      else
        ri[i] = i;
    } else {
      if (cl[i] != ls) cnt = 0, ls = cl[i];
      l[i] = ++cnt;
    }
  }
  cin >> q;
  while (q--) {
    cin >> a >> b >> len;
    if (push_front[a + len - 1] - push_front[a - 1] !=
        push_front[b + len - 1] - push_front[b - 1]) {
      cout << "No\n";
      continue;
    }
    if (push_front[a + len - 1] - push_front[a - 1] == 0 ||
        push_front[a + len - 1] - push_front[a - 1] == len) {
      cout << "Yes\n";
      continue;
    }
    if (comp(a, a + len - 1) == comp(b, b + len - 1))
      cout << "Yes\n";
    else
      cout << "No\n";
  }
  return 0;
}
