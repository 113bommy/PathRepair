#include <bits/stdc++.h>
using namespace std;
int n, m, k;
char s[500011], t[500011], mod[500011 << 1];
int z1[500011 << 1], z2[500011 << 1], t1[500011], t2[500011];
vector<int> v1[500011], v2[500011];
template <class T>
struct BIT {
  int c[500011], inf, n;
  T op;
  void init(int x = 0) {
    inf = x;
    for (int i = 1; i <= n; ++i) c[i] = inf;
  }
  int query(int x) {
    int ans = inf;
    for (int i = x; i; i -= (i & -i))
      if (op(c[i], ans)) ans = c[i];
    return ans;
  }
  void add(int x, int p) {
    for (int i = x; i <= n; i += (i & -i))
      if (op(p, c[i])) c[i] = p;
  }
};
BIT<less<int> > b1;
BIT<greater<int> > b2;
void zfunc(char *s, int n, int *z) {
  int l = 0, r = 0, pt;
  z[1] = n;
  for (int i = 2; i <= n; ++i) {
    if (r < i) {
      for (pt = i; pt <= n && s[pt] == s[pt - i + 1]; ++pt)
        ;
      --pt;
      z[i] = pt - i + 1;
      if (z[i]) l = i, r = pt;
    } else {
      int b = r - i + 1, i_ = i - l + 1;
      if (z[i_] < b)
        z[i] = z[i_];
      else {
        for (pt = r + 1; pt <= n && s[pt] == s[pt - i + 1]; ++pt)
          ;
        --pt;
        z[i] = pt - i + 1;
        l = i;
        r = pt;
      }
    }
  }
}
int main() {
  scanf("%d%d%d%s%s", &n, &m, &k, s + 1, t + 1);
  memcpy(mod + 1, t + 1, m);
  mod[m + 1] = '$';
  memcpy(mod + m + 2, s + 1, n);
  zfunc(mod, n + m + 1, z1);
  for (int i = 1; i <= n; ++i) z1[i] = z1[i + m + 1];
  reverse(t + 1, t + 1 + m);
  reverse(s + 1, s + 1 + n);
  memcpy(mod + 1, t + 1, m);
  mod[m + 1] = '$';
  memcpy(mod + m + 2, s + 1, n);
  zfunc(mod, n + m + 1, z2);
  for (int i = 1; i <= n; ++i) z2[i] = z2[i + m + 1];
  reverse(z2 + 1, z2 + 1 + n);
  reverse(t + 1, t + 1 + m);
  reverse(s + 1, s + 1 + n);
  if (m <= k) {
    for (int i = 1; i <= n; ++i)
      if (z2[i] == m && max(1, i - k + 1) + 2 * k - 1 <= n) {
        printf("Yes\n%d %d\n", max(1, i - k + 1), max(1, i - k + 1) + k);
        return 0;
      }
    for (int i = n; i >= 1; --i)
      if (z1[i] == m && min(n, i + k - 1) - 2 * k + 1 >= 1) {
        printf("Yes\n%d %d\n", min(n, i + k - 1) - k + 1,
               min(n, i + k - 1) - 2 * k + 1);
        return 0;
      }
  }
  b1.n = b2.n = n;
  b1.init(0x3f3f3f3f);
  b2.init(-0x3f3f3f3f);
  for (int i = 1; i <= n; ++i) v1[z1[i]].push_back(i), v2[z2[i]].push_back(i);
  for (int i = n; i > k; --i) {
    int s1 = v1[i].size();
    for (int j = 0; j < s1; ++j) b1.add(n - v1[i][j] + 1, v1[i][j]);
    int s2 = v2[i].size();
    for (int j = 0; j < s2; ++j) b2.add(v2[i][j], v2[i][j]);
  }
  for (int i = k; i >= 1; --i) {
    int s1 = v1[i].size();
    for (int j = 0; j < s1; ++j) b1.add(n - v1[i][j] + 1, v1[i][j]);
    int s2 = v2[i].size();
    for (int j = 0; j < s2; ++j) b2.add(v2[i][j], v2[i][j]);
    t1[i] = b1.query(n - k + i);
    t2[i] = b2.query(n - k + i);
  }
  for (int i = max(1, m - k); i <= min(m, k); ++i)
    if (t2[m - i] >= t1[i] + m - 1) {
      printf("Yes\n%d %d\n", t1[i] + i - k, t2[m - i] - (m - i) + 1);
      return 0;
    }
  printf("No\n");
  return 0;
}
