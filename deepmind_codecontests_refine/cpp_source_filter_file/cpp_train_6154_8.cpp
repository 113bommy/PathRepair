#include <bits/stdc++.h>
using namespace std;
long long kq, cd, p[500001], cur, mn[500001], done[200005];
long long aug[500001], red[500001];
vector<pair<long long, long long> > block[500001];
struct custom_hash {
  size_t operator()(long long x) const { return x; }
};
unordered_map<long long, pair<long long, long long>, custom_hash> a[500001];
pair<long long, long long> get(long long u, long long i) {
  pair<long long, long long> kq = pair<long long, long long>(0, 0);
  while (i > 0) {
    if (a[u].find(i) != a[u].end())
      kq.first += a[u][i].first, kq.second += a[u][i].second;
    i -= i & -i;
  }
  return kq;
}
void update(long long u, long long i, long long val) {
  while (i <= cd) a[u][i].first += val, a[u][i].second += 1, i += i & -i;
}
long long dad(long long u) {
  while (p[u] != 0) u = p[u];
  return u;
}
void add(long long u, pair<long long, long long> key) {
  long long val = key.first, v = key.second;
  pair<long long, long long> sp = get(u, val);
  kq -= (-red[u] + aug[u]);
  if (block[u].size() == 0) mn[u] = v;
  if (mn[u] > v) red[u] += get(u, cd).first * (mn[u] - v), mn[u] = v;
  red[u] += val * (v - mn[u]);
  aug[u] += val * (block[u].size() - sp.second) + sp.first;
  kq += (-red[u] + aug[u]);
  update(u, val, val);
  block[u].push_back(key);
  done[mn[u] + block[u].size() - 1] = 1;
  if (mn[u] + block[u].size() - 1 != u) p[mn[u] + block[u].size() - 1] = u;
}
void fused(long long u, long long v) {
  if (block[u].size() < block[v].size()) swap(u, v);
  p[v] = u;
  if (block[v].size() == 0) return;
  kq -= (-red[v] + aug[v]);
  for (auto x : block[v]) add(u, x);
  long long nx = mn[u] + block[u].size();
  long long dadnx = dad(nx);
  if (done[nx] == 1 && dadnx != u) fused(u, dadnx);
}
void inp() { cin >> cd; }
void do_it() {
  long long u, v;
  for (long long i = 1; i <= cd; i++) {
    cin >> u >> v;
    done[u] = 1;
    if (u != 1 && done[u - 1] != 0) {
      long long dadu = dad(u), dadu1 = dad(u - 1);
      if (dadu != dadu1) fused(dadu, dadu1);
    }
    if (u != cd && done[u + 1] != 0) {
      long long dadu = dad(u), dadu1 = dad(u + 1);
      if (dadu != dadu1) fused(dadu, dadu1);
    }
    add(dad(u), pair<long long, long long>(v, u));
    long long dadu = dad(u);
    long long nx = mn[dadu] + block[dadu].size();
    long long dadnx = dad(nx);
    if (done[nx] == 1 && dadnx != dadu) fused(dadu, dadnx);
    cout << kq << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  inp();
  do_it();
}
