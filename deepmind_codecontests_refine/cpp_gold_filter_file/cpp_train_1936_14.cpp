#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10, NUM = 1e9;
const int MN = 3e5 + 10;
vector<int> st[MN], en[MN];
int change_time[MN];
short tp[MN];
int arr[MN];
int L[MN], R[MN], val[MN], pl[MN], ans[MN];
int n, q;
int seg[MN << 2], seg2[MN << 2];
map<int, vector<int> > mp;
int ps_l[MN], ps_r[MN];
pair<int, int> Res;
void fail() {
  cout << "NO\n";
  exit(0);
}
int func(int a) {
  while (__builtin_popcount(a) > 1) a &= a - 1;
  return a - 1;
}
void upd(int id, int b, int e, int p, int val) {
  if (e - b == 1) {
    seg[id] = val;
    return;
  }
  int mid = b + e >> 1;
  if (p < mid)
    upd(id << 1, b, mid, p, val);
  else
    upd(id << 1 | 1, mid, e, p, val);
  seg[id] = min(seg[id << 1], seg[id << 1 | 1]);
}
int get(int id, int b, int e, int l, int r) {
  if (r <= b || e <= l) return NUM + 1;
  if (l <= b && e <= r) return seg[id];
  int mid = b + e >> 1;
  return min(get(id << 1, b, mid, l, r), get(id << 1 | 1, mid, e, l, r));
}
void upd2(int id, int b, int e, int p, int val) {
  if (e - b == 1) {
    seg2[id] = val;
    return;
  }
  int mid = b + e >> 1;
  if (p < mid)
    upd2(id << 1, b, mid, p, val);
  else
    upd2(id << 1 | 1, mid, e, p, val);
  seg2[id] = max(seg2[id << 1], seg2[id << 1 | 1]);
}
int get2(int id, int b, int e, int l, int r) {
  if (r <= b || e <= l) return 0;
  if (l <= b && e <= r) return seg2[id];
  int mid = b + e >> 1;
  return max(get2(id << 1, b, mid, l, r), get2(id << 1 | 1, mid, e, l, r));
}
void Make() {
  vector<int> My;
  for (int i = 0; i < q; ++i) upd(1, 0, q, i, NUM + 1);
  for (int i = 0; i < n; ++i) {
    for (auto x : st[i]) upd(1, 0, q, x, ans[x]);
    arr[i] = get(1, 0, q, 0, change_time[i]);
    if (arr[i] == NUM + 1) My.push_back(i), arr[i] = 0;
    for (auto x : en[i]) upd(1, 0, q, x, NUM + 1);
  }
  if (((int)(My).size()) > 1) {
    for (auto x : My) arr[x] = (1 << 29) - 1;
    arr[My[0]] = (1 << 29);
  }
  for (int i = 0; i < n; ++i) ps_l[i + 1] = ps_l[i] | arr[i];
  for (int i = n - 1; ~i; --i) ps_r[i] = ps_r[i + 1] | arr[i];
  for (int i = 0; i < n; ++i) upd2(1, 0, n, i, arr[i]);
  for (int i = 0; i < q; ++i) {
    if (tp[i] == 1) {
      if (get2(1, 0, n, L[i], R[i] + 1) != ans[i]) fail();
      mp[ans[i]].resize(0);
    } else
      upd2(1, 0, n, pl[i], val[i]);
  }
  for (int i = 0; i < n; ++i) mp[arr[i]].push_back(i);
  Res = {ps_l[n], -1};
  for (int i = 0; i < n; ++i) upd2(1, 0, n, i, arr[i]);
  for (int i = 0; i < q; ++i) {
    if (tp[i] == 1) {
      for (auto x : mp[ans[i]])
        if (max(get2(1, 0, n, L[i], x), get2(1, 0, n, x + 1, R[i] + 1)) ==
            ans[i]) {
          int V = ps_l[x] | ps_r[x + 1];
          V |= func(arr[x]);
          if (V > Res.first) Res = {V, x};
        }
    } else
      upd2(1, 0, n, pl[i], val[i]);
  }
  if (~Res.second) arr[Res.second] = func(arr[Res.second]);
  if (((int)(My).size()) == 1) {
    int ind = My[0], V = Res.first, Lim = NUM;
    for (int i = 29; ~i; --i)
      if (!((1 << i) & V)) {
        if (Lim >= (1 << i)) arr[ind] |= (1 << i), Lim -= (1 << i);
      }
  }
  cout << "YES\n";
  for (int i = 0; i < n; ++i) cout << arr[i] << ' ';
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  fill(change_time, change_time + MN, q);
  for (int i = 0; i < q; ++i) {
    cin >> tp[i];
    if (tp[i] == 1) {
      cin >> L[i] >> R[i] >> ans[i];
      --L[i], --R[i];
      st[L[i]].push_back(i);
      en[R[i]].push_back(i);
    } else {
      cin >> pl[i] >> val[i], --pl[i];
      change_time[pl[i]] = min(change_time[pl[i]], i);
    }
  }
  Make();
  return 0;
}
