#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
int N, K, ans;
string s;
vector<int> A[MAXN];
struct UF {
  int par[MAXN], sz[MAXN], enemy[MAXN], on[MAXN];
  void init() {
    for (int i = 1; i <= K; i++) sz[i] = 1, par[i] = i;
    memset(on, -1, sizeof(on));
  }
  int fp(int p) { return par[p] = p == par[p] ? p : fp(par[p]); }
  int uni(int a, int b) {
    if (a == 0 || b == 0) return max(a, b);
    a = fp(a);
    b = fp(b);
    if (on[a] != -1 || on[b] != -1) on[b] = max(on[a], on[b]);
    sz[b] += sz[a];
    par[a] = b;
    return b;
  }
  int val(int x) {
    int a = fp(x), b = enemy[a];
    if (on[a] == 1) return sz[a];
    if (on[b] == 1) return sz[b];
    return min(sz[a], sz[b]);
  }
  void same(int a, int b) {
    a = fp(a);
    b = fp(b);
    int x = uni(a, b), y = uni(enemy[a], enemy[b]);
    enemy[x] = y;
    if (y != 0) enemy[y] = x;
    if (on[x] != -1) on[y] = 1 - on[x];
    if (y != 0 && on[y] != -1) on[x] = 1 - on[y];
  }
  void diff(int a, int b) {
    a = fp(a);
    b = fp(b);
    int x = uni(a, enemy[b]), y = uni(b, enemy[a]);
    enemy[x] = y;
    enemy[y] = x;
    if (on[x] != -1) on[y] = 1 - on[x];
    if (on[y] != -1) on[x] = 1 - on[y];
  }
} uf;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> K;
  cin >> s;
  for (int i = 1; i <= K; i++) {
    int c;
    cin >> c;
    for (int j = 1; j <= c; j++) {
      int x;
      cin >> x;
      A[x].push_back(i);
    }
  }
  uf.init();
  for (int i = 1; i <= N; i++) {
    if (A[i].size() == 1) {
      int a = uf.fp(A[i][0]), b = uf.enemy[a];
      ans -= uf.val(a);
      if (s[i - 1] == '0') {
        uf.on[a] = 1;
        uf.on[b] = 0;
      } else {
        uf.on[a] = 0;
        uf.on[b] = 1;
      }
      ans += uf.val(a);
    }
    if (A[i].size() == 2) {
      int a = uf.fp(A[i][0]), b = uf.fp(A[i][1]);
      if (s[i - 1] == '1' && a != b) {
        ans -= uf.val(a) + uf.val(b);
        uf.same(a, b);
        ans += uf.val(a);
      }
      if (s[i - 1] == '0' && a != uf.enemy[b]) {
        ans -= uf.val(a) + uf.val(b);
        uf.diff(a, b);
        ans += uf.val(a);
      }
    }
    cout << ans << '\n';
  }
}
