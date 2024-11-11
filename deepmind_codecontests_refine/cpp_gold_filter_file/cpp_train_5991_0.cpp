#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
int n, out[N], in[N], q[N], tot;
pair<int, int> p[N];
long long ans[N];
bool pd[N];
vector<pair<int, int> > v[N * 4], tmp;
struct Node {
  int l, r;
} t[N * 4];
void build(int x, int l, int r) {
  t[x].l = l, t[x].r = r;
  if (l == r) return;
  int mid = (l + r) / 2;
  build(x * 2, l, mid);
  build(x * 2 + 1, mid + 1, r);
}
void insert(int x, int l, int r, pair<int, int> &p) {
  if (l == t[x].l && r == t[x].r) {
    v[x].push_back(p);
    return;
  }
  int mid = (t[x].l + t[x].r) / 2;
  if (r <= mid)
    insert(x * 2, l, r, p);
  else if (l > mid)
    insert(x * 2 + 1, l, r, p);
  else
    insert(x * 2, l, mid, p), insert(x * 2 + 1, mid + 1, r, p);
}
void retrieve(int x) {
  sort(v[x].begin(), v[x].end());
  tmp.clear();
  int tail = 0;
  for (int i = 0; i < v[x].size(); i++) {
    while (tail >= 2 && 1ll * (tmp[tail - 2].first - tmp[tail - 1].first) *
                                (tmp[tail - 1].second - v[x][i].second) >=
                            1ll *
                                (tmp[tail - 2].second - tmp[tail - 1].second) *
                                (tmp[tail - 1].first - v[x][i].first))
      tmp.pop_back(), tail--;
    tmp.push_back(v[x][i]);
    tail++;
  }
  v[x] = tmp;
  if (t[x].l == t[x].r) {
    int k = -q[t[x].l];
    bool flag = false;
    long long res = -2e18;
    int now = x, l, r, mid;
    while (now) {
      l = 0, r = v[now].size() - 1;
      while (l < r) {
        mid = (l + r) / 2;
        if (1ll * k * (v[now][mid].first - v[now][mid + 1].first) >=
            v[now][mid].second - v[now][mid + 1].second)
          l = mid + 1;
        else
          r = mid;
      }
      if (r >= 0) {
        flag = true;
        res = max(res, 1ll * v[now][l].first * q[t[x].l] + v[now][l].second);
      }
      now >>= 1;
    }
    if (flag) {
      pd[t[x].l] = true;
      ans[t[x].l] = res;
    }
    return;
  }
  retrieve(x * 2);
  retrieve(x * 2 + 1);
}
int main() {
  scanf("%d", &n);
  int t, x, y;
  tot = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &x, &y);
      p[i] = make_pair(x, y);
      in[i] = tot + 1;
      pd[i] = true;
      out[i] = -1;
    } else if (t == 2) {
      scanf("%d", &x);
      out[x] = tot;
    } else {
      scanf("%d", &x);
      q[++tot] = x;
    }
  }
  if (tot == 0) return 0;
  build(1, 1, tot);
  for (int i = 1; i <= n; i++)
    if (pd[i]) {
      if (out[i] == -1) out[i] = tot;
      if (in[i] <= out[i]) insert(1, in[i], out[i], p[i]);
    }
  memset(pd, false, sizeof(pd));
  retrieve(1);
  for (int i = 1; i <= tot; i++)
    if (pd[i])
      printf("%I64d\n", ans[i]);
    else
      puts("EMPTY SET");
  return 0;
}
