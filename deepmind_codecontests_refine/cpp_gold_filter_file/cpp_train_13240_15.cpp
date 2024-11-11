#include <bits/stdc++.h>
using namespace std;
vector<vector<int> > g;
vector<int> in, out;
int TIME = 0;
const int N = 1 << 19;
long long A[2 * N];
long long getval(int l) {
  l += N;
  long long s = 0;
  while (l) {
    s += A[l];
    l /= 2;
  }
  return s;
}
long long t[2 * N];
long long add[2 * N];
void update(int v, int tl, int tr, int l, int r, int a) {
  if (l > r) return;
  if (l == tl && tr == r) {
    t[v] += a;
    add[v] += a;
  } else {
    int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v] += add[v];
    t[2 * v + 1] += add[v];
    add[v] = 0;
    update(v * 2, tl, tm, l, min(r, tm), a);
    update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, a);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
}
void addval(int l, int r, int val) {
  l += N;
  r += N;
  while (l <= r) {
    if (l & 1) {
      A[l] += val;
      ++l;
    }
    if (!(r & 1)) {
      A[r] += val;
      --r;
    }
    if (l > r) break;
    l /= 2;
    r /= 2;
  }
}
long long get_max(int v, int tl, int tr, int l, int r) {
  if (l > r) return -1e9;
  if (l == tl && tr == r) {
    return t[v];
  } else {
    int tm = (tl + tr) / 2;
    add[2 * v] += add[v];
    add[2 * v + 1] += add[v];
    t[2 * v] += add[v];
    t[2 * v + 1] += add[v];
    add[v] = 0;
    return max(get_max(v * 2, tl, tm, l, min(r, tm)),
               get_max(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
  }
}
void dfs(int v) {
  in[v] = TIME++;
  for (int nv : g[v]) {
    dfs(nv);
  }
  out[v] = TIME++;
}
vector<int> f(vector<int> a) {
  int n = a.size();
  vector<int> res(n);
  g.assign(n, vector<int>());
  in.resize(n);
  out.resize(n);
  vector<int> pos(n), pr(n);
  for (int i = 0; i < n; ++i) {
    pos[a[i]] = i;
  }
  for (int t = 0; t < 2; ++t) {
    vector<int> q;
    for (int j = 0; j < n; ++j) {
      int i = t == 0 ? j : n - 1 - j;
      int cand = -1;
      while (!q.empty() && a[q.back()] > a[i]) {
        cand = q.back();
        q.pop_back();
      }
      if (cand != -1) {
        g[i].push_back(cand);
        pr[cand] = i;
      }
      q.push_back(i);
    }
  }
  TIME = 0;
  dfs(0);
  vector<vector<int> > g1(n);
  for (int i = 0; i < 2 * N; ++i) t[i] = -n - 1;
  memset(A, 0, sizeof(A));
  memset(add, 0, sizeof(add));
  for (int i = 0; i < n; ++i) {
    update(1, 0, N - 1, in[i], in[i],
           getval(in[i]) - get_max(1, 0, N - 1, in[i], in[i]));
    update(1, 0, N - 1, in[i], out[i], 1);
    res[i] = get_max(1, 0, N - 1, 0, TIME + 1);
    addval(in[i], out[i], 1);
  }
  return res;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  int s = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    --a[i];
    if (a[i] == 0) s = i;
  }
  vector<int> l, r;
  for (int i = 0; i < n; ++i) {
    l.push_back(a[(s - i + n) % n]);
    r.push_back(a[(s + i + n) % n]);
  }
  vector<int> hl = f(l);
  vector<int> hr = f(r);
  int mi = n + 1, best = 0;
  for (int i = 0; i < n; ++i) {
    int cand = max(hl[i], hr[n - 1 - i]);
    if (cand < mi) {
      mi = cand;
      best = (s - i + n) % n;
    }
  }
  cout << mi << ' ' << best << endl;
  return 0;
}
