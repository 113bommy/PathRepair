#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int n;
int sz;
int trie[43 * M][2];
void add(long long x) {
  int node = 0;
  for (int i = 43; i >= 0; i--) {
    int on = ((x & (1LL << i)) > 0);
    if (trie[node][on]) {
      node = trie[node][on];
    } else {
      trie[node][on] = ++sz;
      node = trie[node][on];
    }
  }
}
long long query(long long x) {
  int node = 0;
  long long path = 0;
  for (int i = 43; i >= 0; i--) {
    int onX = ((x & (1LL << i)) > 0);
    if (onX) {
      if (trie[node][0]) {
        node = trie[node][0];
      } else {
        path |= 1LL << i;
        node = trie[node][1];
      }
    } else {
      if (trie[node][1]) {
        path |= 1 << i;
        node = trie[node][1];
      } else {
        node = trie[node][0];
      }
    }
  }
  return path;
}
long long get(vector<long long>& ar) {
  sz = 0;
  memset(trie, 0, sizeof trie);
  long long prf = 0, ret = 0;
  for (int i = 0; i < (int)ar.size(); i++) {
    prf ^= ar[i];
  }
  ret = prf;
  long long suf = 0;
  add(0);
  for (int i = (int)ar.size() - 1; i >= 0; i--) {
    suf ^= ar[i];
    prf ^= ar[i];
    add(suf);
    ret = max(ret, max(prf, suf));
    ret = max(ret, prf ^ query(prf));
  }
  return ret;
}
int main() {
  scanf("%d ", &n);
  vector<long long> cur;
  for (int i = 1; i <= n; i++) {
    long long x;
    scanf("%lld", &x);
    cur.push_back(x);
  }
  long long ans = get(cur);
  reverse(cur.begin(), cur.end());
  ans = max(ans, get(cur));
  printf("%lld\n", ans);
}
