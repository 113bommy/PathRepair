#include <bits/stdc++.h>
using namespace std;
int ri() {
  int x;
  scanf("%d", &x);
  return x;
}
const int N = 200000, L = N + N, Q = 500000;
char a[L];
int start[N + 1], sa[L], rnk[L], plcp[L], fenwick[L], ans[Q];
pair<int, int> rg[N];
vector<pair<int, int> > q[N];
namespace KoAluru {
bool *t;
int *b;
template <typename T>
void bucket(T a[], int n, int k, bool end) {
  fill_n(b, k, 0);
  for (int i = (0); i < (n); i++) b[a[i]]++;
  if (end)
    for (int i = (1); i < (k); i++) b[i] += b[i - 1];
  else {
    int s = 0;
    for (int i = (0); i < (k); i++) s += b[i], b[i] = s - b[i];
  }
}
template <typename T>
void plus_to_minus(T a[], int sa[], int n, int k) {
  bucket(a, n, k, false);
  sa[b[a[n - 1]]++] = n - 1;
  for (int i = (0); i < (n - 1); i++) {
    int j = sa[i] - 1;
    if (j >= 0 && !t[j]) sa[b[a[j]]++] = j;
  }
}
template <typename T>
void minus_to_plus(T a[], int sa[], int n, int k) {
  bucket(a, n, k, true);
  for (int i = (n); --i >= (0);) {
    int j = sa[i] - 1;
    if (j >= 0 && t[j]) sa[--b[a[j]]] = j;
  }
}
template <typename T>
void ka(const T a[], int n, int k, int sa[]) {
  t[n - 1] = false;
  for (int i = (n - 1); --i >= (0);)
    t[i] = a[i] < a[i + 1] || a[i] == a[i + 1] && t[i + 1];
  bool minor = 2 * count(t, t + n, false) > n;
  bucket(a, n, k, minor);
  fill_n(sa, n, -1);
  if (minor) {
    for (int i = (0); i < (n); i++)
      if (t[i]) sa[--b[a[i]]] = i;
    plus_to_minus(a, sa, n, k);
    minus_to_plus(a, sa, n, k);
  } else {
    sa[b[a[n - 1]]++] = n - 1;
    for (int i = (0); i < (n - 1); i++)
      if (!t[i]) sa[b[a[i]]++] = i;
    minus_to_plus(a, sa, n, k);
    plus_to_minus(a, sa, n, k);
  }
  int last = -1, name = 0, nn = count(t, t + n, minor);
  int *sa2, *pi;
  if (minor)
    sa2 = sa, pi = sa + n - nn;
  else
    sa2 = sa + n - nn, pi = sa;
  fill_n(b, n, -1);
  for (int i = (0); i < (n); i++)
    if (sa[i] >= 0 && minor == t[sa[i]]) {
      bool diff = last == -1;
      int p = sa[i];
      if (!diff)
        for (int j = (0); j < (n); j++) {
          if (last + j >= n || p + j >= n || a[last + j] != a[p + j] ||
              t[last + j] != t[p + j]) {
            diff = true;
            break;
          } else if (j > 0 && (minor == t[last + j] || minor == t[p + j]))
            break;
        }
      if (diff) {
        name++;
        last = p;
      }
      b[p] = name - 1;
    }
  nn = 0;
  for (int i = (0); i < (n); i++)
    if (b[i] >= 0) pi[nn++] = b[i];
  if (name < nn)
    ka(pi, nn, name, sa2);
  else
    for (int i = (0); i < (nn); i++) sa2[pi[i]] = i;
  for (int i = (nn); --i >= (0);)
    t[i] = a[i] < a[i + 1] || a[i] == a[i + 1] && t[i + 1];
  nn = 0;
  bucket(a, n, k, minor);
  if (minor) {
    for (int i = (0); i < (n); i++)
      if (minor == t[i]) pi[nn++] = i;
    for (int i = (0); i < (nn); i++) sa[i] = pi[sa2[i]];
    for (int i = (nn); --i >= (0);) {
      int j = sa[i];
      sa[i] = -1;
      sa[--b[a[j]]] = j;
    }
  } else {
    for (int i = (0); i < (n); i++)
      if (minor == t[i]) pi[nn++] = i;
    for (int i = (nn); --i >= (0);) sa[n - nn + i] = pi[sa2[i]];
    for (int i = (0); i < (nn); i++) {
      int j = sa[n - nn + i];
      sa[n - nn + i] = -1;
      sa[b[a[j]]++] = j;
    }
  }
  if (minor)
    plus_to_minus(a, sa, n, k);
  else
    minus_to_plus(a, sa, n, k);
}
template <typename T>
void main(const T a[], int n, int k, int sa[], int b[]) {
  if (n > 0) {
    KoAluru::b = b;
    t = new bool[n];
    ka(a, n, k, sa);
    delete[] t;
  }
}
void calc_rank(const int sa[], int n, int rnk[]) {
  for (int i = (0); i < (n); i++) rnk[sa[i]] = i;
}
template <typename T>
void calc_lcp(T a[], int sa[], int n, int lcp[], int plcp[]) {
  for (int i = (0); i < (n); i++) plcp[sa[i]] = i ? sa[i - 1] : -1;
  int l = 0;
  for (int i = (0); i < (n); i++) {
    int j = plcp[i];
    if (j != -1)
      for (; a[i + l] == a[j + l]; l++)
        ;
    plcp[i] = l;
    l &&l--;
  }
  for (int i = (0); i < (n); i++) lcp[i] = plcp[sa[i]];
  vector<pair<int, int> > S;
  size_t p = 0;
  S.emplace_back(-1, n);
  while (p < S.size()) {
    pair<int, int> x = S[p++];
    if (x.first + 1 == x.second)
      plcp[x.second] = x.second == n ? 0 : lcp[x.second];
    else {
      int i = (x.first + x.second) / 2;
      S.emplace_back(x.first, i);
      S.emplace_back(i, x.second);
    }
  }
  while (p) {
    pair<int, int> x = S[--p];
    if (x.first + 1 < x.second) {
      int i = (x.first + x.second) / 2,
          t0 = ((x.first) + 1 == (i) ? plcp[i]
                                     : plcp[n + 1 + ((x.first) + (i)) / 2]),
          t1 = ((i) + 1 == (x.second) ? plcp[x.second]
                                      : plcp[n + 1 + ((i) + (x.second)) / 2]);
      plcp[n + 1 + i] = min(t0, t1);
    }
  }
}
template <typename T>
int get_lcp(const T a[], int n, const T b[], int m) {
  int l = 0;
  n = min(n, m);
  for (int i = (0); i < (n); i++)
    if (a[i] != b[i]) return i;
  return n;
}
template <typename T>
pair<int, int> interval(const T a[], const int sa[], const int plcp[], int n,
                        const T b[], int m) {
  int l = -1, xl = 0, h = n, xh = 0;
  while (l + 1 < h) {
    int i = (l + h) / 2,
        yl = ((l) + 1 == (i) ? plcp[i] : plcp[n + 1 + ((l) + (i)) / 2]),
        yh = ((i) + 1 == (h) ? plcp[h] : plcp[n + 1 + ((i) + (h)) / 2]);
    if (xl <= yh && yh < xh)
      l = i, xl = yh;
    else if (xl <= xh && xh < yh)
      h = i;
    else if (xl > yl && yl >= xh)
      h = i, xh = yl;
    else if (yl > xl && xl >= xh)
      l = i;
    else {
      int y = max(xl, xh);
      y += get_lcp(a + sa[i] + y, n - sa[i] - y, b + y, m - y);
      if (y == m) {
        int e = i;
        while (l + 1 < e) {
          int j = (l + e) / 2;
          if (((j) + 1 == (e) ? plcp[e] : plcp[n + 1 + ((j) + (e)) / 2]) < m)
            l = j;
          else
            e = j;
        }
        if (((l) + 1 == (e) ? plcp[e] : plcp[n + 1 + ((l) + (e)) / 2]) >= m)
          l = max(l - 1, -1);
        e = i;
        while (e + 1 < h) {
          int j = (e + h) / 2;
          if (((e) + 1 == (j) ? plcp[j] : plcp[n + 1 + ((e) + (j)) / 2]) < m)
            h = j;
          else
            e = j;
        }
        if (((e) + 1 == (h) ? plcp[h] : plcp[n + 1 + ((e) + (h)) / 2]) >= m)
          h = min(h + 1, n);
        break;
      } else if (y == n - sa[i] || y != m && a[sa[i] + y] < b[y])
        l = i, xl = y;
      else
        h = i, xh = y;
    }
  }
  return {l + 1, h};
}
};  // namespace KoAluru
int getSum(int x) {
  int s = 0;
  for (; x; x &= x - 1) s += fenwick[x - 1];
  return s;
}
int main() {
  int n = ri(), m = ri(), len = 0;
  for (int i = (0); i < (n); i++) {
    scanf("%s", a + len);
    start[i] = len;
    len += strlen(a + len) + 1;
  }
  start[n] = len;
  KoAluru::main(a, len, 256, sa, rnk);
  KoAluru::calc_lcp(a, sa, len, rnk, plcp);
  KoAluru::calc_rank(sa, len, rnk);
  for (int i = (0); i < (m); i++) {
    int x = ri() - 1, y = ri() - 1, z = ri() - 1;
    if (x) q[x - 1].emplace_back(z, 2 * i);
    q[y].emplace_back(z, 2 * i + 1);
  }
  for (int i = (0); i < (n); i++)
    rg[i] = KoAluru::interval(a, sa, plcp, len, a + start[i],
                              start[i + 1] - start[i] - 1);
  for (int i = (0); i < (n); i++) {
    for (int j = start[i]; a[j]; j++)
      for (int x = rnk[j]; x < len; x |= x + 1) fenwick[x]++;
    for (auto qq : q[i]) {
      pair<int, int> r = rg[qq.first];
      ans[qq.second / 2] +=
          (qq.second % 2 ? 1 : -1) * (getSum(r.second) - getSum(r.first));
    }
  }
  for (int i = (0); i < (m); i++) printf("%d\n", ans[i]);
}
