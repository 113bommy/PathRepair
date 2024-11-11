#include <bits/stdc++.h>
using namespace std;
const int N = 300019, LOG = 29, MAX = 1e9, INF = 2e9;
int n, m, seg[4 * N], seg2[4 * N];
bool mark[N];
int t[N], l[N], r[N], x[N], k[N], d[N];
int a[N];
vector<int> unb;
set<int> s;
void __query(int id, int p, int vl, int s = 0, int e = n) {
  if (e - s < 2) {
    seg2[id] = vl;
    return;
  }
  int mid = (s + e) / 2;
  if (p < mid)
    __query(2 * id, p, vl, s, mid);
  else
    __query(2 * id + 1, p, vl, mid, e);
  seg2[id] = max(seg2[2 * id], seg2[2 * id + 1]);
  return;
}
int __get(int id, int L, int R, int s = 0, int e = n) {
  if (L <= s && e <= R) return seg2[id];
  if (L >= e || s >= R) return -INF;
  int mid = (s + e) / 2;
  return max(__get(2 * id, L, R, s, mid), __get(2 * id + 1, L, R, mid, e));
}
bool validate() {
  for (int i = 0; i < n; i++) __query(1, i, a[i]);
  for (int i = 0; i < m; i++) {
    if (t[i] == 1) {
      if (__get(1, l[i], r[i]) != x[i]) return false;
    } else {
      __query(1, k[i], d[i]);
    }
  }
  return true;
}
void query(int id, int L, int R, int vl, int s = 0, int e = n) {
  if (L <= s && e <= R) {
    seg[id] = min(seg[id], vl);
    return;
  }
  if (L >= e || s >= R) return;
  int mid = (s + e) / 2;
  query(2 * id, L, R, vl, s, mid);
  query(2 * id + 1, L, R, vl, mid, e);
}
int get(int id, int p, int s = 0, int e = n) {
  int vl = seg[id];
  if (e - s < 2) {
    return vl;
  }
  int mid = (s + e) / 2;
  if (p < mid)
    return min(vl, get(2 * id, p, s, mid));
  else
    return min(vl, get(2 * id + 1, p, mid, e));
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < 4 * N; i++) seg[i] = INF;
  for (int i = 0; i < m; i++) {
    cin >> t[i];
    if (t[i] == 1) {
      cin >> l[i] >> r[i] >> x[i];
      l[i]--;
      query(1, l[i], r[i], x[i]);
    } else {
      cin >> k[i] >> d[i];
      k[i]--;
      if (!mark[k[i]]) {
        a[k[i]] = get(1, i);
      }
      mark[k[i]] = true;
    }
  }
  for (int i = 0; i < n; i++) {
    if (!mark[i]) a[i] = get(1, i);
  }
  if (!validate()) return cout << "NO\n", 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == INF)
      unb.push_back(i);
    else {
      if (s.count(a[i])) {
        int p = 1;
        while (p <= a[i]) {
          p = p * 2 + 1;
        }
        a[i] = p / 2;
      } else {
        s.insert(a[i]);
      }
    }
  }
  if (unb.size() >= 2) {
    int id1 = unb[0], id2 = unb[1];
    a[id1] = (1 << 29);
    a[id2] = (1 << 29) - 1;
    for (auto x : unb) {
      if (x != id1 && x != id2) a[x] = 0;
    }
  } else if (unb.size() == 1) {
    int mor = 0, id = unb[0];
    for (int i = 0; i < n; i++) {
      if (i != unb[0]) mor |= a[i];
    }
    a[id] = 0;
    for (int j = LOG; j >= 0; j--) {
      if ((mor & (1 << j)) == 0) {
        if (a[id] + (1 << j) <= MAX) a[id] += (1 << j);
      }
    }
  }
  cout << "YES\n";
  for (int i = 0; i < n; i++) cout << a[i] << ' ';
  cout << endl;
}
