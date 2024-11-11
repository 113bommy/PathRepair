#include <bits/stdc++.h>
using namespace std;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};
const int N = 100010;
int n;
int v[N * 4], tr[N * 4];
int mt[N * 4];
int query(int no, int l, int r, int i, int j) {
  if (r < i || l > j) return -0x3F3F3F3F;
  if (l >= i && r <= j) return tr[no];
  int nxt = (no << 1);
  int mid = (l + r) >> 1;
  int p1 = query(nxt, l, mid, i, j);
  int p2 = query(nxt + 1, mid + 1, r, i, j);
  if (p1 == -0x3F3F3F3F)
    return p2;
  else if (p2 == -0x3F3F3F3F)
    return p1;
  else
    return (v[p1] > v[p2]) ? p1 : p2;
}
void update(int no, int l, int r, int i, int val) {
  if (l == r) {
    tr[no] = l;
    v[l] = max(val, v[l]);
    return;
  }
  int nxt = (no << 1);
  int mid = (l + r) >> 1;
  if (i <= mid)
    update(nxt, l, mid, i, val);
  else
    update(nxt + 1, mid + 1, r, i, val);
  int p1 = tr[nxt];
  int p2 = tr[nxt + 1];
  if (p1 == -0x3F3F3F3F)
    tr[no] = p2;
  else if (p2 == -0x3F3F3F3F)
    tr[no] = p1;
  else
    tr[no] = (v[p1] > v[p2]) ? p1 : p2;
}
int l[N], r[N];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", mt + i);
  int lis = 0;
  for (int i = 0; i < n; ++i) {
    int p = query(1, 0, N, 0, mt[i] - 1);
    l[i] = v[p] + 1;
    lis = max(lis, 1 + v[p]);
    update(1, 0, 100000, mt[i], 1 + v[p]);
  }
  memset(v, 0, sizeof v);
  memset(tr, 0, sizeof tr);
  for (int i = n - 1; i >= 0; --i) {
    int p = query(1, 0, N, mt[i] + 1, N);
    r[i] = v[p] + 1;
    update(1, 0, N, mt[i], 1 + v[p]);
  }
  string resp;
  resp.resize(n, '1');
  for (int i = 0; i < n; ++i)
    if (l[i] + r[i] - 1 == lis) resp[i] = '3';
  vector<pair<int, int> > foo;
  for (int i = 0; i < n; ++i) {
    if (l[i] + r[i] - 1 != lis) continue;
    foo.push_back(make_pair(l[i] - 1, i));
  }
  sort(foo.begin(), foo.end());
  for (int i = 1; i < (int)foo.size(); ++i)
    if (foo[i - 1].first == foo[i].first)
      resp[foo[i - 1].second] = resp[foo[i].second] = '2';
  printf("%s\n", resp.c_str());
  return 0;
}
