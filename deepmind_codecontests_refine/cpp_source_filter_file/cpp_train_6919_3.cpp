#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e4 + 10;
map<int, vector<pair<int, int> > > mpa, mpd;
vector<int> ps;
int arr[2 * maxn], C;
int a[maxn], b[maxn], c[maxn], d[maxn], n, m, k;
long long mn[4 * maxn], cn[4 * maxn], lz[4 * maxn];
void build(int l = 0, int r = C - 1, int id = 1) {
  if ((r - l) == 1) {
    cn[id] = arr[r] - arr[l];
    return;
  }
  int mid = (l + r) / 2;
  build(l, mid, 2 * id);
  build(mid, r, 2 * id + 1);
  cn[id] = cn[2 * id] + cn[2 * id + 1];
}
void get(int l, int r, int ind) {
  mn[ind] += lz[ind];
  if (l != r) {
    lz[2 * ind] += lz[ind];
    lz[2 * ind + 1] += lz[ind];
  }
  lz[ind] = 0;
}
void add(int f, int s, int x, int l = 0, int r = C - 1, int ind = 1) {
  if (f >= s || l >= r) return;
  get(l, r, ind);
  if (s <= l || r <= f) return;
  if (f <= l && r <= s) {
    lz[ind] += x;
    get(l, r, ind);
    return;
  }
  int mid = (l + r) / 2;
  add(f, s, x, l, mid, 2 * ind);
  add(f, s, x, mid, r, 2 * ind + 1);
  mn[ind] = min(mn[2 * ind], mn[2 * ind + 1]);
  cn[ind] = 0;
  if (mn[ind] == mn[2 * ind]) cn[ind] += cn[2 * ind];
  if (mn[ind] == mn[2 * ind + 1]) cn[ind] += cn[2 * ind + 1];
}
bool solve() {
  memset(mn, 0, sizeof mn);
  memset(cn, 0, sizeof cn);
  memset(lz, 0, sizeof lz);
  ps.clear();
  mpa.clear();
  mpd.clear();
  C = 0;
  for (int i = 0; i < m; i++) {
    if (a[i] < c[i] && b[i] < d[i]) {
      mpa[b[i]].push_back({a[i], c[i]});
      mpd[d[i]].push_back({a[i], c[i]});
      ps.push_back(b[i]);
      ps.push_back(d[i]);
      arr[C++] = a[i];
      arr[C++] = c[i];
    }
  }
  if (C == 0) return 0;
  sort(arr, arr + C);
  sort(ps.begin(), ps.end());
  C = unique(arr, arr + C) - arr;
  ps.resize(unique(ps.begin(), ps.end()) - ps.begin());
  build();
  bool ans = 0;
  int psb = 0;
  for (int pos : ps) {
    ans ^= (pos - psb) & (arr[C - 1] - arr[0] - (mn[1] != 0 ? 0 : cn[1])) & 1;
    psb = pos;
    for (pair<int, int> p : mpd[pos])
      add(lower_bound(arr, arr + C, p.first) - arr,
          lower_bound(arr, arr + C, p.second) - arr, -1);
    for (pair<int, int> p : mpa[pos])
      add(lower_bound(arr, arr + C, p.first) - arr,
          lower_bound(arr, arr + C, p.second) - arr, 1);
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < m; i++) {
    scanf("%d%d%d%d", &a[i], &b[i], &c[i], &d[i]);
    c[i]++, d[i]++;
  }
  while (k > 0) {
    if (solve()) {
      printf("Hamed\n");
      return 0;
    }
    for (int i = 0; i < m; i++) {
      a[i] = (a[i] + 1) / 2;
      b[i] = (b[i] + 1) / 2;
      c[i] = (c[i] + 1) / 2;
      d[i] = (d[i] + 1) / 2;
    }
    k >>= 1;
  }
  printf("Malek\n");
  return 0;
}
