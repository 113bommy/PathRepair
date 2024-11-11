#include <bits/stdc++.h>
using namespace std;
inline void read(int &x) {
  int v = 0, f = 1;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void read(long long &x) {
  long long v = 0ll, f = 1ll;
  char c = getchar();
  while (!isdigit(c) && c != '-') c = getchar();
  if (c == '-')
    f = -1;
  else
    v = (c & 15);
  while (isdigit(c = getchar())) v = (v << 1) + (v << 3) + (c & 15);
  x = v * f;
}
inline void readc(char &x) {
  char c;
  while (((c = getchar()) == ' ') || c == '\n')
    ;
  x = c;
}
int n, m, i, j, ca, cb, fa[200005];
long long ans[200005], res, sum[1600005];
int id[1600005];
int vis[1600005];
struct nda {
  int h, l, r, id;
} a[200005];
struct ndb {
  int op, h, x, id;
} b[200005];
bool cmpa(nda x, nda y) { return x.h < y.h; }
bool cmpb(ndb x, ndb y) {
  if (x.h == y.h) return x.op > y.op;
  return x.h < y.h;
}
vector<int> allx, ally;
int fnd(int x) {
  if (fa[x] == x) return x;
  return fa[x] = fnd(fa[x]);
}
void pushup(int x) {
  sum[x] = sum[x + x] + sum[x + x + 1];
  id[x] = max(id[x + x], id[x + x + 1]);
}
void dfs(int x, int d) {
  if (vis[x] || !id[x] || x >= 800000) return;
  vis[x] = 1;
  if (id[x + x] && id[x + x + 1]) {
    fa[fnd(id[x + x])] = fnd(id[x + x + 1]);
  }
  dfs(x + x, d);
  dfs(x + x + 1, d);
}
void update(int x, int l, int r, int y, int c, int d) {
  vis[x] = 0;
  if (l == r) {
    id[x] = c;
    sum[x] = d;
    return;
  }
  int mid = (l + r) / 2;
  if (y <= mid)
    update(x + x, l, mid, y, c, d);
  else
    update(x + x + 1, mid + 1, r, y, c, d);
  pushup(x);
}
long long query(int x, int l, int r, int ql, int qr, int d) {
  if (ql <= l && r <= qr) {
    if (id[x]) {
      fa[fnd(id[x])] = fnd(d);
      dfs(x, d);
    }
    return sum[x];
  }
  int mid = (l + r) / 2;
  long long res = 0;
  if (ql <= mid) res += query(x + x, l, mid, ql, qr, d);
  if (qr > mid) res += query(x + x + 1, mid + 1, r, ql, qr, d);
  return res;
}
int main() {
  read(n);
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    fa[i] = i;
    int x1, y111111111111111111111111111, x2, y2;
    read(x1);
    read(y111111111111111111111111111);
    read(x2);
    read(y2);
    if (x1 == x2) {
      a[++ca] = (nda){x1, y111111111111111111111111111, y2, i};
    } else {
      ans[i] = x2 - x1 + 1;
      b[++cb] = (ndb){1, x1, y111111111111111111111111111, i};
      b[++cb] = (ndb){-1, x2, y111111111111111111111111111, 0};
    }
    allx.push_back(x1);
    allx.push_back(x2);
    ally.push_back(y111111111111111111111111111);
    ally.push_back(y2);
  }
  sort((allx).begin(), (allx).end());
  allx.resize(unique((allx).begin(), (allx).end()) - allx.begin());
  sort((ally).begin(), (ally).end());
  ally.resize(unique((ally).begin(), (ally).end()) - ally.begin());
  for (((i)) = (1); ((i)) <= ((ca)); ((i))++) {
    a[i].h = upper_bound((allx).begin(), (allx).end(), a[i].h) - allx.begin();
    a[i].l = upper_bound((ally).begin(), (ally).end(), a[i].l) - ally.begin();
    a[i].r = upper_bound((ally).begin(), (ally).end(), a[i].r) - ally.begin();
  }
  for (((i)) = (1); ((i)) <= ((cb)); ((i))++) {
    b[i].h = upper_bound((allx).begin(), (allx).end(), b[i].h) - allx.begin();
    b[i].x = upper_bound((ally).begin(), (ally).end(), b[i].x) - ally.begin();
  }
  sort(a + 1, a + ca + 1, cmpa);
  sort(b + 1, b + cb + 1, cmpb);
  int j = 1, k = 1;
  for (((i)) = (1); ((i)) <= ((allx.size())); ((i))++) {
    while (k <= cb && b[k].h == i && b[k].op == 1) {
      update(1, 1, ally.size(), b[k].x, b[k].id, 1);
      k++;
    }
    while (j <= ca && a[j].h == i) {
      ans[a[j].id] = ally[a[j].r - 1] - ally[a[j].l - 1] + 1 -
                     query(1, 1, ally.size(), a[j].l, a[j].r, a[j].id);
      j++;
    }
    while (k <= cb && b[k].h == i && b[k].op == -1) {
      update(1, 1, ally.size(), b[k].x, 0, 0);
      k++;
    }
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    if (fnd(i) != i) ans[fnd(i)] += ans[i];
  }
  for (((i)) = (1); ((i)) <= ((n)); ((i))++) {
    if (fnd(i) == i) {
      res = max(res, ans[i]);
    }
  }
  cout << res - 1 << endl;
  return 0;
}
