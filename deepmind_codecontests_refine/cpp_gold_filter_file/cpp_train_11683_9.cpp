#include <bits/stdc++.h>
using namespace std;
const int LEN = 501000;
char s[LEN];
int n, _sa[LEN], _b[LEN], _tmp[LEN], top[LEN], *SA = _sa, *B = _b, *tmp = _tmp;
long long LCP[LEN];
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
  for (int i = 0, k = 0; i < n; i++) {
    if (B[i] == n - 1) continue;
    int j = SA[B[i] + 1];
    for (; s[i + k] == s[j + k]; k++)
      ;
    LCP[B[i]] = min(k, n >> 1);
    if (k) k--;
  }
}
int k;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> s >> k;
  n = strlen(s);
  if ((long long)n * (n + 1) / 2 < (long long)k) {
    cout << "No such line.\n";
    return 0;
  }
  n++;
  build_sa();
  build_lcp();
  --k;
  int len = 1, beg = 1, pos = 1;
  while (k || len >= n - SA[pos]) {
    if (len >= n - SA[pos]) {
      len = LCP[pos] + 1;
      ++beg;
      ++pos;
      continue;
    }
    if (LCP[pos] < len) {
      ++len;
      pos = beg;
    } else {
      ++pos;
    }
    --k;
  }
  for (int i = SA[pos], j = 0; j < len; ++j, ++i) {
    cout << s[i];
  }
  cout << endl;
  return 0;
}
