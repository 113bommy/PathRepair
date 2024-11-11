#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
namespace SA {
const int maxlen = 1000000;
const int alphabet = 1000000;
int pn[maxlen], cn[maxlen];
int cnt[alphabet], c[maxlen];
int n;
void buildSA(int s[], int sa[], int lcp[] = 0) {
  int i, h;
  fill(cnt, cnt + alphabet, 0);
  for (i = 0; i < n; i++) cnt[s[i]]++;
  for (i = 1; i < alphabet; i++) cnt[i] += cnt[i - 1];
  for (i = 0; i < n; i++) sa[--cnt[s[i]]] = i;
  c[sa[0]] = 0;
  int classes = 1;
  for (i = 1; i < n; i++) {
    if (s[sa[i]] != s[sa[i - 1]]) classes++;
    c[sa[i]] = classes - 1;
  }
  for (h = 1; h < n; h *= 2) {
    for (i = 0; i < n; i++) {
      pn[i] = sa[i] - h;
      if (pn[i] < 0) pn[i] += n;
    }
    fill(cnt, cnt + classes, 0);
    for (i = 0; i < n; i++) cnt[c[pn[i]]]++;
    for (i = 1; i < classes; i++) cnt[i] += cnt[i - 1];
    for (i = n - 1; i >= 0; i--) sa[--cnt[c[pn[i]]]] = pn[i];
    cn[sa[0]] = 0;
    classes = 1;
    for (i = 1; i < n; i++) {
      int mid1 = (sa[i] + h) % n, mid2 = (sa[i - 1] + h) % n;
      if (c[sa[i]] != c[sa[i - 1]] || c[mid1] != c[mid2]) classes++;
      cn[sa[i]] = classes - 1;
    }
    for (i = 0; i < n; i++) c[i] = cn[i];
  }
  if (lcp) {
    for (i = 0; i < n; i++) pn[sa[i]] = i;
    for (int i = 0, k = 0; i < n; i++) {
      if (pn[i] != n - 1) {
        for (int j = sa[pn[i] + 1]; s[i + k] == s[j + k];) k++;
        lcp[pn[i]] = k;
        if (k) k--;
      }
    }
  }
}
}  // namespace SA
int n;
string a[200000];
long long ans;
long long c[200000];
char in[600000];
int m;
int mix[1000000];
int sa[1000000];
int dat[1000000];
int ldat[1000000];
int S;
int lcp[1000000];
int it[2100000];
long long sit[2100000];
void update(int x) {
  for (x /= 2; x > 0; x /= 2) it[x] = min(it[x * 2], it[x * 2 + 1]);
}
int getmin(int x, int y) {
  int mi = 0x3f3f3f3f;
  while (x <= y) {
    if (x % 2 == 1) mi = min(mi, it[x++]);
    if (y % 2 == 0) mi = min(mi, it[y--]);
    x /= 2, y /= 2;
  }
  return mi;
}
void supdate(int x) {
  for (x /= 2; x > 0; x /= 2) sit[x] = sit[x * 2] + sit[x * 2 + 1];
}
long long getsum(int x, int y) {
  long long sum = 0;
  while (x <= y) {
    if (x % 2 == 1) sum += sit[x++];
    if (y % 2 == 0) sum += sit[y--];
    x /= 2, y /= 2;
  }
  return sum;
}
int main() {
  int i, j, k;
  cin >> n;
  for (i = 0; i < n; i++) {
    scanf("%s", in);
    a[i] = string(in);
  }
  for (i = 0; i < n; i++) scanf("%lld", &c[i]);
  for (i = 0; i < n; i++) {
    int u = 0;
    for (auto e : a[i]) dat[m] = i, ldat[m] = u++, mix[m++] = e;
    dat[m] = -1, mix[m++] = 200 + i;
  }
  SA::n = m;
  SA::buildSA(mix, sa, lcp);
  for (S = 1; S < m; S *= 2)
    ;
  for (i = 0; i < m - 1; i++) it[S + i] = lcp[i], update(S + i);
  for (i = 0; i < m; i++)
    sit[S + i] = dat[sa[i]] != -1 ? c[dat[sa[i]]] : 0, supdate(S + i);
  for (i = 0; i < m; i++) {
    if (dat[i] == -1) continue;
    int u = sa[i];
    for (k = 0; k < 2; k++) {
      int tar = !k ? a[dat[u]].size() - ldat[u] : lcp[i];
      if (tar == 0) continue;
      int low, high, mid;
      int s, e;
      low = i, high = m - 1;
      while (low <= high) {
        mid = (low + high) / 2;
        if (getmin(S + i, S + mid) < tar)
          high = mid - 1;
        else
          low = mid + 1;
      }
      e = low;
      low = 0, high = i;
      while (low <= high) {
        mid = (low + high) / 2;
        if (getmin(S + mid, S + i - 1) < tar)
          low = mid + 1;
        else
          high = mid - 1;
      }
      s = low;
      ans = max(ans, getsum(S + s, S + e) * (long long)tar);
    }
  }
  cout << ans;
  return 0;
}
