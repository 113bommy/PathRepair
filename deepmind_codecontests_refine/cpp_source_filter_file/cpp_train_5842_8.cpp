#include <bits/stdc++.h>
using namespace std;
int n, a[1000010], b[1000010];
long long k, w[1000010];
struct Trie {
  int ch[2], v;
  void clear() { ch[0] = ch[1] = v = 0; }
} T[1000010 * 2];
int top = 1, rt = 1;
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> k;
  for (int i = 2; i <= n; ++i) {
    int x;
    long long y;
    cin >> x >> y;
    w[i] = w[x] ^ y;
  }
  for (int i = 1; i <= n; ++i) a[i] = b[i] = rt;
  for (int o = 61; ~o; --o) {
    top = o & 1 ? 1 : n + 1;
    for (int i = 1; i <= n; ++i) {
      int &p = a[i], d = w[i] >> o & 1;
      if (!T[p].ch[d]) {
        T[++top].clear();
        T[p].ch[d] = top;
      }
      ++T[p = T[p].ch[d]].v;
    }
    long long s = 0;
    for (int i = 1; i <= n; ++i) {
      int p = b[i], d = w[i] >> o & 1;
      s += T[T[p].ch[d]].v;
    }
    int v = 0;
    if (k > s) k -= s, ans |= 1 << o, v = 1;
    for (int i = 1; i <= n; ++i) {
      int &p = b[i], d = w[i] >> o & 1;
      p = T[p].ch[d ^ v];
    }
  }
  cout << ans << endl;
  return 0;
}
