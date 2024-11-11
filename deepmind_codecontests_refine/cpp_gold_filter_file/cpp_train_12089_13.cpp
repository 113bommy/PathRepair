#include <bits/stdc++.h>
using namespace std;
string S;
int s;
int sa[200005], ra[200005], tsa[200005], tra[200005], freq[200005];
void cSort(int k) {
  memset(freq, 0, sizeof(freq));
  for (int i = (0); i <= (s - 1); i += (1)) freq[(i + k < s ? ra[i + k] : 0)]++;
  for (int i = (1); i <= (max(s, 300)); i += (1)) freq[i] += freq[i - 1];
  for (int i = (s - 1); i >= (0); i -= (1))
    tsa[--freq[sa[i] + k < s ? ra[sa[i] + k] : 0]] = sa[i];
  for (int i = (0); i <= (s - 1); i += (1)) sa[i] = tsa[i];
}
int rsa[200005];
void SuffixArray() {
  for (int i = (0); i <= (s - 1); i += (1)) {
    sa[i] = i;
    ra[i] = S[i];
  }
  for (int k = 1; k < s; k <<= 1) {
    cSort(k);
    cSort(0);
    tra[sa[0]] = 0;
    for (int i = (1); i <= (s - 1); i += (1)) {
      tra[sa[i]] = tra[sa[i - 1]] + 1;
      if (ra[sa[i]] == ra[sa[i - 1]] &&
          (sa[i] + k < s ? ra[sa[i] + k] : 0) ==
              (sa[i - 1] + k < s ? ra[sa[i - 1] + k] : 0)) {
        tra[sa[i]]--;
      }
    }
    for (int i = (0); i <= (s - 1); i += (1)) ra[i] = tra[i];
    if (ra[s - 1] == s - 1) break;
  }
  for (int i = (0); i <= (s - 1); i += (1)) rsa[sa[i]] = i;
}
int phi[200005], plcp[200005], lcp[18][200005];
void LCP() {
  phi[sa[0]] = -1;
  for (int i = (1); i <= (s - 1); i += (1)) phi[sa[i]] = sa[i - 1];
  int l = 0;
  for (int i = (0); i <= (s - 1); i += (1)) {
    if (phi[i] == -1) {
      l = 0;
      continue;
    }
    while (i + l < s && phi[i] + l < s && S[i + l] == S[phi[i] + l]) l++;
    plcp[i] = l;
    l = max(l - 1, 0);
  }
  for (int i = (1); i <= (s - 1); i += (1)) lcp[0][i] = plcp[sa[i]];
  for (int i = (1); i <= (17); i += (1)) {
    for (int j = (0); j <= (s - 1); j += (1)) {
      lcp[i][j] = lcp[i - 1][j];
      int p = j - (1 << (i - 1));
      if (p >= 0) lcp[i][j] = min(lcp[i][j], lcp[i - 1][p]);
    }
  }
}
int power[400005];
int ulcp[19][400005], dlcp[19][400005];
long long up[400005], down[400005];
int num[200005], num2[200005], comb[400005], psum[400005];
int findlcp(int i, int j) {
  if (i > j) swap(i, j);
  if (i == j) return (s - sa[i] - 1);
  int p = power[j - i];
  i += (1 << p);
  return min(lcp[p][i], lcp[p][j]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> s >> q >> S;
  S += '$';
  s++;
  SuffixArray();
  LCP();
  power[1] = 0;
  int index = 0;
  for (int i = (2); i <= (s); i += (1)) {
    if ((1 << (index + 1)) == i) index++;
    power[i] = index;
  }
  for (int i = (1); i <= (q); i += (1)) {
    int a, b;
    cin >> a >> b;
    for (int j = (0); j <= (a - 1); j += (1)) {
      cin >> num[j];
      num[j] = rsa[num[j] - 1];
    }
    for (int j = (0); j <= (b - 1); j += (1)) {
      cin >> num2[j];
      num2[j] = rsa[num2[j] - 1];
    }
    sort(num, num + a);
    sort(num2, num2 + b);
    int j = 0, k = 0, it = 0;
    while (j < a || k < b) {
      if (k >= b || j < a && num[j] < num2[k]) {
        comb[it] = num[j], j++;
        psum[it] = (it == 0 ? 0 : psum[it - 1]) + 1;
      } else {
        comb[it] = num2[k], k++;
        psum[it] = (it == 0 ? 0 : psum[it - 1]);
      }
      it++;
    }
    for (int j = (1); j <= (it - 1); j += (1)) {
      int l = findlcp(comb[j], comb[j - 1]);
      ulcp[0][j] = dlcp[0][j - 1] = l;
    }
    ulcp[0][0] = dlcp[0][it - 1] = 0;
    for (int i = (1); i <= (18); i += (1)) {
      for (int j = (0); j <= (it - 1); j += (1)) {
        ulcp[i][j] = ulcp[i - 1][j];
        int p = j - (1 << (i - 1));
        if (p >= 0) ulcp[i][j] = min(ulcp[i][j], ulcp[i - 1][p]);
        dlcp[i][j] = dlcp[i - 1][j];
        p = j + (1 << (i - 1));
        if (p <= it - 1) dlcp[i][j] = min(dlcp[i][j], dlcp[i - 1][p]);
      }
    }
    up[0] = 0;
    for (int i = (1); i <= (it - 1); i += (1)) {
      int l = ulcp[0][i];
      int p = i - 1;
      for (int j = (18); j >= (0); j -= (1)) {
        if (ulcp[j][p] < l) continue;
        p -= (1 << j);
        if (p <= 0) break;
      }
      p = max(p, 0);
      up[i] =
          1LL * ulcp[0][i] * (psum[i - 1] - (p == 0 ? 0 : psum[p - 1])) + up[p];
    }
    down[it - 1] = 0;
    for (int i = (it - 2); i >= (0); i -= (1)) {
      int l = dlcp[0][i];
      int p = i + 1;
      for (int j = (18); j >= (0); j -= (1)) {
        if (dlcp[j][p] < l) continue;
        p += (1 << j);
        if (p >= it - 1) break;
      }
      p = min(p, it - 1);
      down[i] = 1LL * dlcp[0][i] * (psum[p] - psum[i]) + down[p];
    }
    long long ans = 0;
    for (int i = (0); i <= (it - 1); i += (1)) {
      if (i == 0 && psum[0] == 0 || i > 0 && psum[i] == psum[i - 1])
        ans += up[i] + down[i];
    }
    printf("%lld\n", ans);
  }
  return 0;
}
