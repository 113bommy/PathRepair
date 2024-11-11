#include <bits/stdc++.h>
using namespace std;
int n, m;
long long p = 1e9 + 7;
long long po[1 << 20], po1[1 << 20];
long long por(long long x, long long e) {
  long long ret = 1;
  while (e) {
    if (e & 1) ret = (ret * x) % p;
    x = (x * x) % p;
    e >>= 1;
  }
  return ret;
}
vector<int> len, len1;
vector<char> chr, chr1;
long long justsegment() {
  long long ret = 0;
  for (int i = 0; i < len.size(); ++i) {
    if (chr[i] == chr1[0]) {
      if (len[i] >= len1[0]) ret += len[i] - len1[0] + 1;
    }
  }
  return ret;
}
long long towsegments() {
  long long ret = 0;
  if (len.size() == 1) return 0;
  for (int i = 1; i < len.size(); ++i) {
    if (chr[i] == chr1[1] && chr[i - 1] == chr1[0]) {
      if (len[i] >= len1[1] && len[i - 1] >= len1[0]) ret++;
    }
  }
  return ret;
}
int main() {
  cin >> n >> m;
  int l;
  char c;
  for (int i = 0; i < n; ++i) {
    scanf("%d-%c", &l, &c);
    if (len.empty()) {
      len.push_back(l);
      chr.push_back(c);
      continue;
    }
    if (c == chr.back())
      len[len.size() - 1] += l;
    else {
      len.push_back(l);
      chr.push_back(c);
    }
  }
  for (int i = 0; i < m; ++i) {
    scanf("%d-%c", &l, &c);
    if (len1.empty()) {
      len1.push_back(l);
      chr1.push_back(c);
      continue;
    }
    if (c == chr1.back())
      len1[len1.size() - 1] += l;
    else {
      len1.push_back(l);
      chr1.push_back(c);
    }
  }
  long long hsh = 0;
  if (len1.size() == 1) {
    cout << justsegment();
    return 0;
  }
  if (len1.size() == 2) {
    cout << towsegments();
    return 0;
  }
  long long totlen = 0;
  for (int i = 1; i < len1.size() - 1; ++i) {
    hsh = (hsh * por(29ll, len1[i])) % p;
    totlen += len1[i];
    hsh = (hsh + ((por(29ll, len1[i]) - 1 + p) % p) * (chr1[i] - 'a' + 1) % p) %
          p;
  }
  long long hsh1 = 0, totlen1 = 0, ans = 0;
  int st = 0, en = 1;
  while (en < len.size() - 1) {
    hsh1 = (hsh1 * por(29ll, len[en])) % p;
    totlen1 += len[en];
    hsh1 =
        (hsh1 + ((por(29ll, len[en]) - 1 + p) % p) * (chr[en] - 'a' + 1) % p) %
        p;
    ++en;
    while (totlen1 > totlen) {
      ++st;
      totlen1 -= len[st];
      long long del = ((por(29ll, totlen1) * (por(29ll, len[st]) - 1)) % p) *
                      (chr[st] - 'a' + 1);
      del %= p;
      hsh1 = (hsh1 - del + p) % p;
      hsh1 += p;
      hsh1 %= p;
    }
    if (totlen1 == totlen && hsh == hsh1) {
      if (chr[st] == chr1[0] && chr[en] == chr1.back()) {
        if (len[st] >= len1[0] && len[en] >= len1.back()) ++ans;
      }
    }
  }
  cout << ans;
}
