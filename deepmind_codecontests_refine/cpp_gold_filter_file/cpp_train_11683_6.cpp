#include <bits/stdc++.h>
using namespace std;
const int maxn = (int)1e5 + 50;
int k, n, nn, head[maxn], a[maxn], b[maxn], key[maxn], apos[maxn], l[maxn],
    dif[maxn][20];
string s;
bool mark[maxn];
int modn(int i) {
  i %= nn;
  return i >= 0 ? i : i + nn;
}
void SuffixArray() {
  s += '@';
  nn = s.length();
  for (int i = 0; i < nn; ++i) a[i] = i;
  sort(a, a + nn, [](int i, int j) { return s[i] < s[j]; });
  mark[0] = true;
  for (int i = 1; i < nn; ++i) mark[i] = (s[a[i]] != s[a[i - 1]]);
  for (int len = 1; len <= nn; len *= 2) {
    int nkeys = 0;
    head[0] = 0;
    for (int i = 0; i < nn; ++i) {
      b[i] = modn(a[i] - len);
      if (mark[i]) head[nkeys++] = i;
      key[a[i]] = nkeys - 1;
    }
    if (nkeys == nn) break;
    for (int i = 0; i < nn; ++i) {
      int keyval = key[b[i]];
      a[head[keyval]] = b[i];
      ++head[keyval];
    }
    for (int i = 1; i < nn; ++i)
      if (key[modn(a[i] + len)] != key[modn(a[i - 1] + len)]) mark[i] = true;
  }
}
void LCPArray() {
  for (int i = 0; i < nn; ++i) apos[a[i]] = i;
  int q = 0;
  l[0] = 0;
  for (int i = 0; i < nn - 1; ++i) {
    int j = a[apos[i] - 1];
    while (s[i + q] == s[j + q]) ++q;
    l[apos[i]] = q;
    if (q > 0) --q;
  }
}
int main() {
  cin >> s >> k;
  n = s.length();
  if (k > (long long)n * (n + 1) / 2) {
    cout << "No such line.";
    exit(0);
  }
  SuffixArray();
  LCPArray();
  for (int i = 1; i <= n; ++i) dif[i][0] = l[i];
  for (int j = 1; j < 20; ++j) {
    for (int i = 1; i <= n; ++i) {
      if (i + (1 << j) - 1 > n)
        dif[i][j] = 0;
      else
        dif[i][j] = min(dif[i][j - 1], dif[i + (1 << (j - 1))][j - 1]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = l[i] + 1; a[i] + j <= n; ++j) {
      int now = i + 1;
      for (int t = 19; t >= 0; --t)
        if (dif[now][t] >= j) now += (1 << t);
      now = min(now, n + 1);
      if (now - i >= k) {
        cout << s.substr(a[i], j);
        exit(0);
      } else
        k -= (now - i);
    }
  }
}
