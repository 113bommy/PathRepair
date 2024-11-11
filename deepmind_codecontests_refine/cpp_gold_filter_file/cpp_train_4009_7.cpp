#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
using namespace std;
int a, b, c, d, n, m, k;
char str[502];
inline void tr(const vector<int>& a, vector<int>& r1, vector<int>& r2) {
  for (int _n(((int)((a).size()) / 2) - 1), i(0); i <= _n; i++) {
    r1[i] = a[i] + a[i + (int)((a).size()) / 2];
    if (r1[i] >= 1000000007) r1[i] -= 1000000007;
    r2[i] = a[i];
  }
}
vector<int> mul_or(const vector<int>& a, const vector<int>& b) {
  if ((int)((a).size()) <= 8) {
    vector<int> res((int)((a).size()));
    for (int _n(((int)((a).size())) - 1), i(0); i <= _n; i++) {
      for (int _n(((int)((b).size())) - 1), j(0); j <= _n; j++) {
        res[i | j] = (res[i | j] + (long long)a[i] * b[j]) % 1000000007;
      }
    }
    return res;
  }
  vector<int> A1((int)((a).size()) / 2), A2((int)((a).size()) / 2);
  tr(a, A1, A2);
  vector<int> B1((int)((b).size()) / 2), B2((int)((b).size()) / 2);
  tr(b, B1, B2);
  vector<int> M1 = mul_or(A1, B1);
  vector<int> M2 = mul_or(A2, B2);
  vector<int> res((int)((a).size()), 0);
  for (int _n(((int)((a).size()) / 2) - 1), i(0); i <= _n; i++) {
    res[i] = M2[i];
    res[i + (int)((a).size()) / 2] = M1[i] - M2[i];
    if (res[i + (int)((a).size()) / 2] < 0) {
      res[i + (int)((a).size()) / 2] += 1000000007;
    }
  }
  return res;
}
vector<int> mul_and(const vector<int>& a, const vector<int>& b) {
  vector<int> aa((int)((a).size())), bb((int)((b).size()));
  int t = (int)((a).size()) - 1;
  for (int _n(((int)((aa).size())) - 1), i(0); i <= _n; i++) {
    aa[t ^ i] = a[i];
    bb[t ^ i] = b[i];
  }
  vector<int> res = mul_or(aa, bb);
  vector<int> ans((int)((res).size()));
  for (int _n(((int)((res).size())) - 1), i(0); i <= _n; i++) {
    ans[t ^ i] = res[i];
  }
  return ans;
}
vector<int> solve(int l, int r) {
  if (l > r) return vector<int>(1 << 16);
  if (l == r) {
    vector<int> res(1 << 16);
    for (int _n((4) - 1), i(0); i <= _n; i++) {
      for (int _n((2) - 1), j(0); j <= _n; j++) {
        if (str[l] != '?') {
          if (str[l] >= 'a' && str[l] <= 'z') {
            if (!j) continue;
            if ((char)('a' + i) != str[l]) continue;
          } else {
            if (j) continue;
            if ((char)('A' + i) != str[l]) continue;
          }
        }
        int val = 0;
        for (int _n((16) - 1), mask(0); mask <= _n; mask++) {
          if (mask & 1 << i) {
            if (j == 0) {
              val |= 1 << mask;
            }
          } else {
            if (j == 1) {
              val |= 1 << mask;
            }
          }
        }
        ++res[val];
      }
    }
    return res;
  }
  int c = 0;
  int v = -1;
  for (int _n(r), i(l); i <= _n; i++) {
    if (str[i] == '(') {
      ++c;
    } else if (str[i] == ')') {
      --c;
    }
    if (!c) {
      v = i + 1;
      break;
    }
  }
  vector<int> r1 = solve(l + 1, v - 2);
  vector<int> r2 = solve(v + 2, r - 1);
  vector<int> res(1 << 16);
  for (int _n((2) - 1), i(0); i <= _n; i++) {
    if (str[v] != '?') {
      if (str[v] == '|' && i) continue;
      if (str[v] == '&' && !i) continue;
    }
    vector<int> cur;
    if (i) {
      cur = mul_and(r1, r2);
    } else {
      cur = mul_or(r1, r2);
    }
    for (int _n(((int)((cur).size())) - 1), j(0); j <= _n; j++) {
      res[j] += cur[j];
      if (res[j] >= 1000000007) res[j] -= 1000000007;
    }
  }
  return res;
}
int main() {
  gets(str);
  scanf("%d", &n);
  vector<pair<int, int> > know;
  for (int _n((n)-1), i(0); i <= _n; i++) {
    int mask = 0;
    for (int _n((4) - 1), j(0); j <= _n; j++) {
      scanf("%d", &a);
      if (a) mask |= 1 << j;
    }
    scanf("%d", &a);
    know.push_back(make_pair(mask, a));
  }
  n = (int)strlen(str);
  vector<int> res = solve(0, n - 1);
  int ans = 0;
  for (int _n(((int)((res).size())) - 1), mask(0); mask <= _n; mask++) {
    bool ok = 1;
    for (int _n(((int)((know).size())) - 1), j(0); j <= _n; j++) {
      if (((mask >> know[j].first) & 1) != know[j].second) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans += res[mask];
      if (ans >= 1000000007) ans -= 1000000007;
    }
  }
  printf("%d\n", ans);
}
