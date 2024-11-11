#include <bits/stdc++.h>
long long mod = 1000000007;
using namespace std;
int n;
struct node {
  int a[2] = {0};
  int height;
  int bel = 0;
} trie[10000000];
int alloc = 1;
int rev[300005];
int mxlog = 4;
long long powmod(long long a, long long b) {
  long long res = 1;
  a %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
  }
  return res;
}
int push(int x, int val, int h) {
  trie[x].bel++;
  trie[x].height = h;
  if (trie[x].a[val] > 0) {
    return trie[x].a[val];
  }
  alloc++;
  trie[x].a[val] = alloc;
  return trie[x].a[val];
}
void insert(int x) {
  int curr = 1;
  for (int i = mxlog; i >= 0; i--) {
    if (x & (1 << i)) {
      curr = push(curr, 1, i);
    } else
      curr = push(curr, 0, i);
  }
  trie[curr].bel++;
}
int solve() {
  int curr = 1;
  int ans = 0, i;
  for (i = mxlog; i >= 0; i--) {
    if (rev[i]) {
      if ((1 << (i)) > trie[trie[curr].a[1]].bel) {
        curr = trie[curr].a[1];
      } else {
        ans = ans + (1 << i);
        curr = trie[curr].a[0];
      }
    } else {
      if ((1 << (i)) > trie[trie[curr].a[0]].bel) {
        curr = trie[curr].a[0];
      } else {
        ans = ans + (1 << i);
        curr = trie[curr].a[1];
      }
    }
    if (curr == 0) break;
  }
  return ans;
}
int main() {
  int i, j, fl, test;
  int h[3 * 100001] = {0};
  scanf("%d%d", &n, &test);
  for (i = 0; i < n; i++) {
    scanf("%d", &j);
    if (h[j] == 0) insert(j);
    h[j] = 1;
  }
  while (test--) {
    scanf("%d", &j);
    for (i = mxlog; i >= 0; i--) {
      if (j & (1 << i)) rev[i] = rev[i] ^ 1;
    }
    printf("%d\n", solve());
  }
  return 0;
}
