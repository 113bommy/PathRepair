#include <bits/stdc++.h>
using namespace std;
const int LEN = 5e4 + 5, MAXN = 15;
char s[LEN], t[MAXN][LEN];
int n, _sa[LEN], _b[LEN], _tmp[LEN], top[LEN], LCP[LEN], *SA = _sa, *B = _b,
                                                         *tmp = _tmp, sz[MAXN];
void build_sa() {
  int na = (n < 256 ? 256 : n);
  for (int i = 0; i < n; ++i) top[B[i] = s[i]]++;
  for (int i = 1; i < na; ++i) top[i] += top[i - 1];
  for (int i = 0; i < n; ++i) SA[--top[B[i]]] = i;
  for (int ok = 1, j = 0; ok < n && j < n - 1; ok <<= 1) {
    for (int i = 0; i < n; ++i) {
      j = SA[i] - ok;
      if (j < 0) j += n;
      tmp[top[B[j]]++] = j;
    }
    SA[tmp[top[0] = 0]] = j = 0;
    for (int i = 1; i < n; ++i) {
      if (B[tmp[i]] != B[tmp[i - 1]] || B[tmp[i] + ok] != B[tmp[i - 1] + ok])
        top[++j] = i;
      SA[tmp[i]] = j;
    }
    swap(B, SA), swap(SA, tmp);
  }
}
void build_lcp() {
  for (int i = 0, k = 0; i < n; ++i) {
    if (B[i] == n - 1) continue;
    for (int j = SA[B[i] + 1]; s[i + k] == s[j + k]; ++k)
      ;
    LCP[B[i]] = k;
    if (k) --k;
  }
}
int pi[LEN];
void build_pi(char *p, int m) {
  int k = pi[0] = -1;
  for (int i = 0; i < m; ++i) {
    for (; k >= 0 && p[i] != p[k]; k = pi[k])
      ;
    pi[i + 1] = ++k;
  }
}
int kmp_match(char *t, int n, char *p, int m) {
  build_pi(p, m);
  int ans = 0;
  for (int i = 0, k = 0; i < n; ++i) {
    for (; k == m || (k >= 0 && t[i] != p[k]); k = pi[k])
      ;
    if (++k == m) ++ans;
  }
  return ans;
}
int m, l[MAXN], r[MAXN];
bool check(char *s, int n) {
  for (int i = 0; i < m; ++i) {
    int aux = kmp_match(t[i], sz[i], s, n);
    if (aux < l[i] || aux > r[i]) return false;
  }
  return true;
}
int diff_subs() {
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = SA[i] + LCP[i]; j < n - 1; ++j) {
      if (check(s + SA[i], j - SA[i] + 1)) ++ans;
    }
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> m;
  n = strlen(s) + 1;
  for (int i = 0; i < m; ++i) {
    cin >> t[i] >> l[i] >> r[i];
    sz[i] = strlen(t[i]);
  }
  build_sa();
  build_lcp();
  cout << diff_subs() << endl;
  return 0;
}
