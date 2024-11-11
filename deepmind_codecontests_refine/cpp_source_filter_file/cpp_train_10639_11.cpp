#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using piii = pair<int, pii>;
using plll = pair<ll, pll>;
using pib = pair<int, bool>;
using pdi = pair<double, int>;
using pid = pair<int, double>;
using ld = long double;
using piiii = pair<pii, pii>;
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }
ll fpow(ll b, ll exp, ll mod) {
  if (exp == 0) return 1;
  ll t = fpow(b, exp / 2, mod);
  if (exp & 1) return t * t % mod * b % mod;
  return t * t % mod;
}
ll divmod(ll i, ll j, ll mod) {
  i %= mod, j %= mod;
  return i * fpow(j, mod - 2, mod) % mod;
}
struct node {
  int l, r, v, lz;
};
int n, m, a, b, diff[100005];
vector<pii> arr;
node st[300000];
void build(int l, int r, int i) {
  st[i] = {l, r, (int)0x3f3f3f3f3f, -1};
  if (l != r) {
    int mid = (l + r) / 2;
    build(l, mid, i * 2 + 1);
    build(mid + 1, r, i * 2 + 2);
  }
}
void pushDown(int i) {
  int l = i * 2 + 1;
  int r = i * 2 + 2;
  st[l].v = min(st[l].v, st[i].lz);
  st[r].v = min(st[r].v, st[i].lz);
  if (st[l].lz == -1)
    st[l].lz = st[i].lz;
  else
    st[l].lz = min(st[l].lz, st[i].lz);
  if (st[r].lz == -1)
    st[r].lz = st[i].lz;
  else
    st[r].lz = min(st[r].lz, st[i].lz);
  st[i].lz = -1;
}
void update(int l, int r, int v, int i) {
  if (st[i].lz != -1 && st[i].l != st[i].r) pushDown(i);
  if (st[i].l >= l && st[i].r <= r) {
    st[i].v = min(st[i].v, v);
    st[i].lz = v;
  } else {
    int mid = (st[i].l + st[i].r) / 2;
    if (r <= mid)
      update(l, r, v, i * 2 + 1);
    else if (l > mid)
      update(l, r, v, i * 2 + 2);
    else {
      update(l, r, v, i * 2 + 1);
      update(l, r, v, i * 2 + 2);
    }
    st[i].v = min(st[i * 2 + 1].v, st[i * 2 + 2].v);
  }
}
int query(int idx, int i) {
  if (st[i].lz != -1 && st[i].l != st[i].r) pushDown(i);
  if (st[i].l >= idx && st[i].r <= idx) {
    return st[i].v;
  }
  int mid = (st[i].l + st[i].r) / 2;
  if (idx <= mid)
    return query(idx, i * 2 + 1);
  else
    return query(idx, i * 2 + 2);
}
bool cmp(pii &p1, pii &p2) {
  return p1.first - p1.second < p2.first - p2.second;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a >> b;
    diff[max(0, a - b)]++;
    diff[min(m + 1, a + b + 1)]--;
    arr.push_back({a, b});
  }
  sort(arr.begin(), arr.end(), cmp);
  build(0, m, 0);
  update(0, 0, 0, 0);
  int l = 0;
  int idx = 0;
  for (int i = 1; i <= m; i++) {
    diff[i] += diff[i - 1];
    if (!diff[i]) {
      l = i;
      for (int j = 0; j < n; j++) {
        if (arr[j].first < i) {
          int d = i - arr[j].first;
          int v = query(max(0, arr[j].first - d), 0);
          update(max(0, arr[j].first - d), i, v + d - arr[j].second, 0);
        } else {
          int d = arr[j].first - i;
          int v = query(i - 1, 0);
          update(i, min(m, arr[j].first + d), v + d - arr[j].second, 0);
        }
      }
    }
    while (idx < arr.size() && arr[idx].first - arr[idx].second <= i) {
      update(i, min(m, arr[idx].first + arr[idx].second),
             query(max(0, arr[idx].first - arr[idx].second), 0), 0);
      idx++;
    }
  }
  cout << query(m, 0) << "\n";
  return 0;
}
