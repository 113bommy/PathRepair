#include <bits/stdc++.h>
using namespace std;
template <class T1, class T2>
ostream& operator<<(ostream& os, const pair<T1, T2>& p) {
  os << "{" << p.first << "," << p.second << "}";
  return os;
}
const int N = 2e5 + 100;
const int oo = 1e9 + 7;
inline bool leq(int a1, int a2, int b1, int b2) {
  return (a1 < b1 || a1 == b1 && a2 <= b2);
}
inline bool leq(int a1, int a2, int a3, int b1, int b2, int b3) {
  return (a1 < b1 || a1 == b1 && leq(a2, a3, b2, b3));
}
static void radixPass(int* a, int* b, int* r, int n, int K) {
  int* c = new int[K + 1];
  for (int i = 0; i <= K; i++) c[i] = 0;
  for (int i = 0; i < n; i++) c[r[a[i]]]++;
  for (int i = 0, sum = 0; i <= K; i++) {
    int t = c[i];
    c[i] = sum;
    sum += t;
  }
  for (int i = 0; i < n; i++) b[c[r[a[i]]]++] = a[i];
  delete[] c;
}
void suffixArray(int* s, int* SA, int n, int K) {
  int n0 = (n + 2) / 3, n1 = (n + 1) / 3, n2 = n / 3, n02 = n0 + n2;
  int* s12 = new int[n02 + 3];
  s12[n02] = s12[n02 + 1] = s12[n02 + 2] = 0;
  int* SA12 = new int[n02 + 3];
  SA12[n02] = SA12[n02 + 1] = SA12[n02 + 2] = 0;
  int* s0 = new int[n0];
  int* SA0 = new int[n0];
  for (int i = 0, j = 0; i < n + (n0 - n1); i++)
    if (i % 3 != 0) s12[j++] = i;
  radixPass(s12, SA12, s + 2, n02, K);
  radixPass(SA12, s12, s + 1, n02, K);
  radixPass(s12, SA12, s, n02, K);
  int name = 0, c0 = -1, c1 = -1, c2 = -1;
  for (int i = 0; i < n02; i++) {
    if (s[SA12[i]] != c0 || s[SA12[i] + 1] != c1 || s[SA12[i] + 2] != c2) {
      name++;
      c0 = s[SA12[i]];
      c1 = s[SA12[i] + 1];
      c2 = s[SA12[i] + 2];
    }
    if (SA12[i] % 3 == 1)
      s12[SA12[i] / 3] = name;
    else
      s12[SA12[i] / 3 + n0] = name;
  }
  if (name < n02) {
    suffixArray(s12, SA12, n02, name);
    for (int i = 0; i < n02; i++) s12[SA12[i]] = i + 1;
  } else
    for (int i = 0; i < n02; i++) SA12[s12[i] - 1] = i;
  for (int i = 0, j = 0; i < n02; i++)
    if (SA12[i] < n0) s0[j++] = 3 * SA12[i];
  radixPass(s0, SA0, s, n0, K);
  for (int p = 0, t = n0 - n1, k = 0; k < n; k++) {
    int i = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    int j = SA0[p];
    if (SA12[t] < n0 ? leq(s[i], s12[SA12[t] + n0], s[j], s12[j / 3])
                     : leq(s[i], s[i + 1], s12[SA12[t] - n0 + 1], s[j],
                           s[j + 1], s12[j / 3 + n0])) {
      SA[k] = i;
      t++;
      if (t == n02)
        for (k++; p < n0; p++, k++) SA[k] = SA0[p];
    } else {
      SA[k] = j;
      p++;
      if (p == n0)
        for (k++; t < n02; t++, k++)
          SA[k] = (SA12[t] < n0 ? SA12[t] * 3 + 1 : (SA12[t] - n0) * 3 + 2);
    }
  }
  delete[] s12;
  delete[] SA12;
  delete[] SA0;
  delete[] s0;
}
void lcp_construction(int* s, int* SA, int* lcp, int n) {
  int* rank = new int[n];
  for (int i = 0; i < n; i++) rank[SA[i]] = i;
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (rank[i] == n - 1) {
      k = 0;
      continue;
    }
    int j = SA[rank[i] + 1];
    while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
    lcp[rank[i]] = k;
    if (k) k--;
  }
  return;
}
int shift, n;
char s[N];
int ss[N];
int SA[N];
int lcp[N];
int toclass[N];
int class_index[N];
int upper[N];
int L[N];
long long ans[N];
const int K = 23;
int st[N][K + 1];
int lg2[N + 1];
void ini() {
  lg2[1] = 0;
  for (int i = 2; i <= N; i++) lg2[i] = lg2[i / 2] + 1;
}
int f(int i, int j) { return lcp[i] < lcp[j] ? i : j; }
void pre(int n) {
  for (int i = 0; i < n; i++) st[i][0] = f(i, i);
  for (int j = 1; j <= K; j++)
    for (int i = 0; i + (1 << j) <= n; i++)
      st[i][j] = f(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int getf(int L, int R) {
  if (L > R) swap(L, R);
  int j = lg2[R - L + 1];
  return f(st[L][j], st[R - (1 << j) + 1][j]);
}
bool pos(int l, int r) { return (L[r] >= l); }
int rit(int i, int len) {
  int lo = i, hi = shift - 2, mi;
  while (lo < hi) {
    mi = lo + (hi - lo + 1) / 2;
    int lc;
    if (i == mi)
      lc = upper[toclass[SA[i]]] - SA[i];
    else
      lc = lcp[getf(i, mi - 1)];
    if (lc >= len) {
      lo = mi;
    } else
      hi = mi - 1;
  }
  return lo;
}
int lft(int i, int len) {
  int lo = n, hi = i, mi;
  while (lo < hi) {
    mi = lo + (hi - lo) / 2;
    int lc;
    if (i == mi)
      lc = upper[toclass[SA[i]]] - SA[i];
    else
      lc = lcp[getf(mi, i - 1)];
    if (lc >= len) {
      hi = mi;
    } else
      lo = mi + 1;
  }
  return hi;
}
int getans(int i) {
  int lo = 0, hi = upper[toclass[SA[i]]] - SA[i];
  int mi;
  while (lo < hi) {
    mi = lo + (hi - lo + 1) / 2;
    int l = lft(i, mi);
    int r = rit(i, mi);
    if (pos(l, r))
      lo = mi;
    else
      hi = mi - 1;
  }
  return lo;
}
int32_t main() {
  memset(class_index, -1, sizeof class_index);
  ini();
  int k;
  scanf("%d %d", &n, &k);
  shift = 0;
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    int j = 0;
    while (s[j]) {
      ss[shift++] = s[j++] - 'a' + n;
      toclass[shift - 1] = i;
    }
    upper[i] = shift;
    toclass[shift] = -1;
    if (i + 1 < n) ss[shift++] = i + 1;
  }
  toclass[shift] = -1;
  ss[shift++] = 0;
  suffixArray(ss, SA, shift, n + 26);
  lcp_construction(ss, SA, lcp, shift);
  for (int i = 0; i < n; i++) {
    assert(lcp[i] == 0);
  }
  pre(shift);
  set<int> sat;
  for (int i = n; i < shift; i++) {
    assert(toclass[SA[i]] != -1);
    if (class_index[toclass[SA[i]]] != -1) {
      sat.erase(sat.find(class_index[toclass[SA[i]]]));
    }
    class_index[toclass[SA[i]]] = i;
    sat.insert(i);
    while (sat.size() > k) {
      class_index[toclass[SA[*sat.begin()]]] = -1;
      sat.erase(sat.begin());
    }
    if (sat.size() == k) {
      int lo = *sat.begin();
      L[i] = lo;
    } else {
      L[i] = -1;
    }
  }
  for (int i = n; i < shift; i++) {
    ans[toclass[SA[i]]] += getans(i);
  }
  for (int i = 0; i < n; i++) printf("%d ", ans[i]);
  printf("\n");
}
