#include <bits/stdc++.h>
using namespace std;
const int base = 100003;
const int maxn = 1000005;
int n, m, a[maxn], cnt[maxn], Block;
long long ans[maxn], res;
struct data {
  int l, r, id;
} b[maxn];
vector<int> v;
bool comp(data a, data b) {
  if (a.l / Block != b.l / Block) return a.l / Block < b.l / Block;
  return a.r < b.r;
}
void Add(int x, int val) {
  res -= 1ll * cnt[x] * cnt[x] * x;
  cnt[x] += val;
  res += 1ll * cnt[x] * cnt[x] * x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout.tie(0);
  cin.tie(0);
  if (fopen("POWERFUL"
            ".inp",
            "r")) {
    freopen(
        "POWERFUL"
        ".inp",
        "r", stdin);
    freopen(
        "POWERFUL"
        ".out",
        "w", stdout);
  }
  cin >> n >> m;
  Block = sqrt(n);
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= m; ++i) {
    int l, r;
    cin >> l >> r;
    b[i] = {l, r, i};
  }
  sort(b + 1, b + m + 1, comp);
  int curR = 1, curL = 2;
  for (int i = 1; i <= n; ++i) {
    int L = b[i].l, R = b[i].r;
    while (curL > L) {
      Add(a[--curL], 1);
    }
    while (curL < L) {
      Add(a[curL++], -1);
    }
    while (curR > R) {
      Add(a[curR--], -1);
    }
    while (curR < R) {
      Add(a[++curR], 1);
    }
    ans[b[i].id] = res;
  }
  for (int i = 1; i <= m; ++i) cout << ans[i] << "\n";
}
