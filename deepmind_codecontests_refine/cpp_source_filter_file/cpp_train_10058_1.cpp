#include <bits/stdc++.h>
using namespace std;
const unsigned long long B1 = 37LL;
const unsigned long long B2 = 73LL;
const int N = 100010;
char s[50];
int len;
int n, m;
map<pair<unsigned long long, unsigned long long>, bool> idx;
map<pair<unsigned long long, unsigned long long>, bool> vis;
int sol;
inline void back(int pos, unsigned long long hs1, unsigned long long hs2) {
  if (pos == len) {
    if (vis[make_pair(hs1, hs2)]) return;
    vis[make_pair(hs1, hs2)] = 1;
    sol += idx[make_pair(hs1, hs2)];
    return;
  }
  if (s[pos] >= 'a' && s[pos] <= 'e') {
    int d = s[pos] - 'a' + 1;
    back(pos + 1, hs1 * B1 + (unsigned long long)d,
         hs2 * B2 + (unsigned long long)d);
  } else {
    back(pos + 1, hs1, hs2);
    for (int i = 1; i <= 5; ++i)
      back(pos + 1, hs1 * B1 + (unsigned long long)i,
           hs2 * B2 + (unsigned long long)i);
  }
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf(" %s", s);
    len = strlen(s);
    unsigned long long hs1 = 0, hs2 = 0;
    for (int j = 0; j < len; ++j) {
      hs1 *= B1;
      hs1 += (s[j] - 'a' + 1);
      hs2 *= B2;
      hs2 += (s[j] - 'a' + 1);
    }
    idx[make_pair(hs1, hs2)] = 1;
  }
  for (int i = 0; i < m; ++i) {
    vis.clear();
    scanf(" %s", s);
    len = strlen(s);
    sol = 0;
    back(0, 0, 0);
    printf("%d\n", sol);
  }
  return 0;
}
