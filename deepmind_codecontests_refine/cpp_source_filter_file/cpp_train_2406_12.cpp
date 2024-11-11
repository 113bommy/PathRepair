#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 7, M = 998244353;
const double PI = acos(-1);
string l, a, r, tmp;
int ll, rr, n;
int to[N], mx[N], dp[N], arr1[N], arr2[N];
int sm[N];
void go(int *z) {
  int n = tmp.size();
  int L = 0, R = 0;
  for (int i = 1; i < n; i++) {
    if (i > R) {
      L = R = i;
      while (R < n && tmp[R - L] == tmp[R]) R++;
      z[i] = R - L;
      R--;
    } else {
      int k = i - L;
      if (z[k] < R - i + 1)
        z[i] = z[k];
      else {
        L = i;
        while (R < n && tmp[R - L] == tmp[R]) R++;
        z[i] = R - L;
        R--;
      }
    }
  }
}
int ch(int st, int ed) {
  if (ed - st + 1 < l.size()) return 0;
  if (ed - st + 1 > l.size()) return 1;
  int x = arr1[st + l.size() + 1];
  if (x == l.size()) return 1;
  if (a[st + x] < l[x]) return 0;
  return 1;
}
int ch2(int st, int ed) {
  if (ed - st + 1 > r.size()) return 0;
  if (ed - st + 1 < r.size()) return 1;
  int x = arr2[st + r.size() + 1];
  if (x == r.size()) return 1;
  if (a[st + x] > r[x]) return 0;
  return 1;
}
int main() {
  cin >> a >> l >> r;
  tmp = l + '#' + a;
  go(arr1);
  tmp = r + '#' + a;
  go(arr2);
  n = a.size();
  memset(to, -1, sizeof to);
  memset(mx, -1, sizeof mx);
  for (int i = 0; i < n; i++) {
    if (a[i] == '0') {
      if (l == "0") {
        to[i] = i, mx[i] = i;
      }
      continue;
    }
    int l = i, r = n - 1, md;
    while (l <= r) {
      md = (l + r) / 2;
      if (ch(i, md)) {
        r = md - 1;
        to[i] = md;
      } else
        l = md + 1;
    }
    l = i, r = n - 1, md;
    while (l <= r) {
      md = (l + r) / 2;
      if (ch2(i, md)) {
        l = md + 1;
        mx[i] = md;
      } else
        r = md - 1;
    }
  }
  dp[n] = 1;
  sm[n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    if (to[i] == -1 || mx[i] == -1 || to[i] > mx[i]) {
      sm[i] = sm[i + 1];
      continue;
    }
    dp[i] = (sm[to[i] + 1] - sm[mx[i] + 2] + M) % M;
    sm[i] = (dp[i] + sm[i + 1]) % M;
  }
  cout << dp[0] << endl;
}
