#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int n;
int a[50010];
long long k;
long long Ans = 0;
struct node {
  int son[2];
  int size;
  int val[32];
} trie[50010 * 32];
int tot = 0;
void ins(int x) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int c = ((x >> i) & 1);
    if (now) trie[now].size++;
    if (!trie[now].son[c]) {
      trie[now].son[c] = ++tot;
    }
    now = trie[now].son[c];
  }
  trie[now].size++;
}
int query(int x, int val) {
  int now = 0, ret = 0;
  for (int i = 30; i >= 0; i--) {
    int c = ((x >> i) & 1);
    int v = ((val >> i) & 1);
    if (v) {
      now = trie[now].son[c ^ 1];
      if (!now) break;
    } else {
      ret += trie[trie[now].son[c ^ 1]].size;
      now = trie[now].son[c];
      if (!now) break;
    }
  }
  ret += trie[now].size;
  return ret;
}
void ins2(int x) {
  int now = 0;
  for (int i = 30; i >= 0; i--) {
    int c = ((x >> i) & 1);
    if (now) {
      trie[now].size++;
      for (int j = 0; j <= 30; j++) {
        if ((x >> j) & 1) trie[now].val[j]++;
      }
    }
    if (!trie[now].son[c]) {
      trie[now].son[c] = ++tot;
    }
    now = trie[now].son[c];
  }
  trie[now].size++;
  for (int i = 0; i <= 30; i++) {
    if ((x >> i) & 1) trie[now].val[i]++;
  }
}
long long query2(int x, int val) {
  int now = 0;
  long long ret = 0;
  for (int i = 30; i >= 0; i--) {
    int c = ((x >> i) & 1);
    int v = ((val >> i) & 1);
    if (v) {
      now = trie[now].son[c ^ 1];
      if (!now) break;
    } else {
      int T = trie[now].son[c ^ 1];
      if (T) {
        for (int j = 0; j <= 30; j++) {
          if ((x >> j) & 1) {
            ret =
                (ret + 1ll * (trie[T].size - trie[T].val[j]) * (1 << j) % mod) %
                mod;
          } else {
            ret = (ret + 1ll * (trie[T].val[j]) * (1 << j) % mod) % mod;
          }
        }
      }
      now = trie[now].son[c];
      if (!now) break;
    }
  }
  for (int i = 0; i <= 30; i++) {
    if ((x >> i) & 1) {
      ret = (ret + 1ll * (trie[now].size - trie[now].val[i]) * (1 << i) % mod) %
            mod;
    } else {
      ret = (ret + 1ll * (trie[now].val[i]) * (1 << i) % mod) % mod;
    }
  }
  return ret;
}
long long check(int val) {
  for (int i = 0; i <= tot; i++) {
    trie[i].son[0] = trie[i].son[1] = trie[i].size = 0;
  }
  tot = 0;
  long long ret = 0;
  for (int i = 1; i <= n; i++) {
    ret += query(a[i], val);
    ins(a[i]);
  }
  return ret;
}
int main() {
  scanf("%d%lld", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  int l = 0, r = (1 << 30) - 1, ans = 0;
  while (l < r) {
    int mid = (l + r) / 2;
    if (check(mid) >= k) {
      l = mid + 1;
      ans = mid;
    } else
      r = mid;
  }
  ans++;
  long long tot = check(ans);
  Ans = (k - tot) % mod * (ans - 1) % mod;
  memset(trie, 0, sizeof(trie));
  tot = 0;
  for (int i = 1; i <= n; i++) {
    Ans = (Ans + query2(a[i], ans)) % mod;
    ins2(a[i]);
  }
  printf("%lld\n", Ans);
  return 0;
}
