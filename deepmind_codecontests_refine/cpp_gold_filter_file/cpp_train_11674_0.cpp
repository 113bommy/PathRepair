#include <bits/stdc++.h>
using namespace std;
#pragma warning(disable : 4996)
const int N = 2e5 + 5;
long long mn[N * 4], sum[N * 4], wt[N * 4], up[N * 4], t[N * 4];
bool tup[N * 4];
int z[N];
vector<vector<int>> qr;
vector<int> w;
set<int> st;
int n;
void push(int v, int L, int R) {
  if (tup[v]) {
    if (L != R) {
      up[v * 2] = up[v];
      up[v * 2 + 1] = up[v];
      tup[v * 2] = tup[v * 2 + 1] = 1;
    }
    sum[v] = up[v] * (w[R + 1] - w[L]);
    mn[v] = up[v] > 0 ? 0 : sum[v];
    t[v] = up[v];
    tup[v] = 0;
  }
}
long long ques(int l, int r, int v = 1, int L = 0, int R = n - 2) {
  push(v, L, R);
  if (l > r) return 0;
  if (l == L && r == R) return sum[v];
  int m = (L + R) >> 1;
  return ques(l, min(m, r), v * 2, L, m) +
         ques(max(m + 1, l), r, v * 2 + 1, m + 1, R);
}
long double que(int l, int r, long long pref1, long long pref2, int v = 1,
                int L = 0, int R = n - 2) {
  push(v, L, R);
  if (l > r || mn[v] + pref2 - pref1 > 0) return -1;
  if (L == R) {
    return w[L] + (pref2 - pref1) * 1.0 / -t[v];
  }
  int m = (L + R) >> 1;
  long double x = que(l, min(m, r), pref1, pref2, v * 2, L, m);
  if (x < 0)
    return que(max(m + 1, l), r, pref1, pref2 + sum[v * 2], v * 2 + 1, m + 1,
               R);
  return x;
}
void upd(int l, int r, int x, int v = 1, int L = 0, int R = n - 2) {
  push(v, L, R);
  if (l > r) return;
  if (L == l && r == R) {
    up[v] = x;
    tup[v] = 1;
    push(v, L, R);
  } else {
    int m = (L + R) >> 1;
    upd(l, min(m, r), x, v * 2, L, m);
    upd(max(m + 1, l), r, x, v * 2 + 1, m + 1, R);
    mn[v] = min(mn[v * 2], sum[v * 2] + mn[v * 2 + 1]);
    sum[v] = sum[v * 2] + sum[v * 2 + 1];
  }
}
int getIndex(int x) { return lower_bound(w.begin(), w.end(), x) - w.begin(); }
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int type;
    cin >> type;
    int t, s;
    if (type == 1) {
      cin >> t >> s;
      w.push_back(t);
      qr.push_back({type, t, s});
    } else if (type == 2) {
      cin >> t;
      qr.push_back({type, t});
    } else {
      int l, r, v;
      cin >> l >> r >> v;
      w.push_back(l);
      w.push_back(r);
      qr.push_back({type, l, r, v});
    }
  }
  w.push_back(-1);
  w.push_back((int)2e9);
  sort(w.begin(), w.end());
  w.erase(unique(w.begin(), w.end()), w.end());
  n = w.size();
  st.insert(n - 1);
  st.insert(0);
  cout << fixed;
  cout << setprecision(20);
  for (int i = 0; i < q; i++) {
    if (qr[i][0] == 1) {
      int t = qr[i][1], s = qr[i][2];
      t = getIndex(t);
      auto it = st.upper_bound(t);
      upd(t, (*it) - 1, s);
      st.insert(t);
      z[t] = s;
    } else if (qr[i][0] == 2) {
      int t = qr[i][1];
      t = getIndex(t);
      z[t] = 0;
      st.erase(t);
      auto it = st.upper_bound(t);
      upd(t, (*it) - 1, z[*prev(it)]);
    } else {
      int l = *st.lower_bound(getIndex(qr[i][1])), r = getIndex(qr[i][2]) - 1,
          v = qr[i][3];
      if (v == 0) {
        cout << (long double)qr[i][1] << "\n";
        continue;
      }
      long long ps = ques(0, l - 1);
      long double ans = que(l, r, ps, v);
      if (ans < 0)
        cout << -1;
      else
        cout << ans;
      cout << "\n";
    }
  }
  return 0;
}
