#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int N = 2e5 + 10;
const int M = 5e3 + 10;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
const int mod2 = 998244353;
const int mod3 = 1e9 + 9;
const int hash1 = 131;
const int hash2 = 13331;
struct NODE {
  int ch[26];
  int len, fa, cnt;
};
struct SAM {
  int las = 1, tot = 1;
  NODE node[N << 1];
  void init() {
    memset(node, 0, sizeof(node));
    memset(c, 0, sizeof(c));
    las = 1, tot = 1;
  }
  void add(int c) {
    int p = las;
    int np = las = ++tot;
    node[np].len = node[p].len + 1;
    node[np].cnt = 1;
    for (; p && !node[p].ch[c]; p = node[p].fa) node[p].ch[c] = np;
    if (!p)
      node[np].fa = 1;
    else {
      int q = node[p].ch[c];
      if (node[q].len == node[p].len + 1)
        node[np].fa = q;
      else {
        int nq = ++tot;
        node[nq] = node[q];
        node[nq].len = node[p].len + 1;
        node[nq].cnt = 0;
        node[q].fa = node[np].fa = nq;
        for (; p && node[p].ch[c] == q; p = node[p].fa) node[p].ch[c] = nq;
      }
    }
  }
  int c[N << 1], a[N << 1];
  void toposort() {
    for (int i = 1; i <= tot; i++) c[node[i].len]++;
    for (int i = 1; i <= tot; i++) c[i] += c[i - 1];
    for (int i = 1; i <= tot; i++) a[c[node[i].len]--] = i;
    for (int i = tot; i; i--) {
      int x = a[i];
      int fa = node[x].fa;
      node[fa].cnt += node[x].cnt;
    }
  }
} sam;
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string str;
    cin >> str;
    sam.init();
    for (int i = 0; i < str.length(); i++) {
      sam.add(str[i] - 'a');
    }
    sam.toposort();
    long long ans = 0;
    for (int i = 1; i <= sam.tot; i++) {
      NODE x = sam.node[i];
      NODE fa = sam.node[x.fa];
      ans += (long long)(x.len - fa.len) * x.cnt * x.cnt;
    }
    cout << ans << endl;
  }
  return 0;
}
