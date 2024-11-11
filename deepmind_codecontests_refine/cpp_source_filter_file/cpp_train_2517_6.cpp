#include <bits/stdc++.h>
using namespace std;
template <typename T>
void debug_out(T t) {
  cerr << t;
}
template <typename A, typename B>
void debug_out(pair<A, B> u) {
  cerr << "(" << u.first << " " << u.second << ")";
}
template <typename T>
void debug_out(vector<T> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << ", ";
  }
}
template <typename T>
void debug_out(vector<vector<T>> t) {
  int sz = t.size();
  for (int i = 0; i < sz; i++) {
    debug_out(t[i]);
    if (i != sz - 1) cerr << endl;
  }
}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  debug_out(H);
  cerr << " ";
  debug_out(T...);
}
template <typename T>
void debug_out(set<T> a) {
  vector<T> _a;
  for (T t : a) _a.push_back(t);
  debug_out(_a);
}
int n, m;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> m >> n;
  vector<int> a(n);
  vector<int> b(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) cin >> b[i];
  vector<int> aid(n);
  vector<int> bid(n);
  iota(aid.begin(), aid.end(), 0);
  iota(bid.begin(), bid.end(), 0);
  sort(aid.begin(), aid.end(), [&](int x, int y) { return a[x] < a[y]; });
  sort(bid.begin(), bid.end(), [&](int x, int y) { return b[x] < b[y]; });
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  vector<int> cur;
  for (int i = 0; i < 2 * n; i++) {
    if (i < n)
      cur.push_back(i);
    else
      cur.push_back(~(i - n));
  }
  sort(cur.begin(), cur.end(), [&](int x, int y) {
    int vx = (x < 0 ? b[~x] : a[x]);
    int vy = (y < 0 ? b[~y] : a[y]);
    return vx < vy;
  });
  vector<long long> adif(2 * n + 1);
  vector<long long> bdif(2 * n + 1);
  int ca = 0, cb = 0;
  for (int i : cur) {
    if (i >= 0) {
      adif[ca - cb + n] += (ca >= cb ? -a[i] : a[i]);
    } else {
      bdif[cb - ca + n] += (cb >= ca ? -b[~i] : b[~i]);
    }
    (i < 0 ? cb : ca)++;
  }
  long long res = 0;
  long long total = 0;
  int shift = 0;
  ca = 0;
  cb = 0;
  for (int i = 0; i < n; i++) res += abs(a[i] - b[i]);
  total = res;
  for (int i = 0; i < 2 * n; i++) {
    int id = cur[i];
    (id < 0 ? cb : ca)++;
    if (id < 0) {
      total -= bdif[cb - ca - 1 + n] * 2;
      total -= adif[ca - cb + n] * 2;
      bdif[cb - ca - 1 + n] *= -1;
      adif[ca - cb + n] *= -1;
      bdif[n - 1 + cb - ca] -= b[~id];
      bdif[cb - ca - 1 + n] += m + b[~id];
    } else {
      total -= adif[ca - cb - 1 + n] * 2;
      total -= bdif[cb - ca + n] * 2;
      adif[ca - cb - 1 + n] *= -1;
      bdif[cb - ca + n] *= -1;
      adif[n - 1 + ca - cb] -= a[id];
      adif[ca - cb - 1 + n] += m + a[id];
    }
    total += m;
    if (total < res) {
      shift = i + 1;
      res = total;
    }
  }
  cout << res << endl;
  int al = 0, bl = 0;
  for (int i = 0; i < shift; i++) {
    int id = cur[i];
    if (id < 0) {
      bl++;
    } else {
      al++;
    }
  }
  rotate(aid.begin(), aid.begin() + al, aid.end());
  rotate(bid.begin(), bid.begin() + bl, bid.end());
  vector<int> ans(n);
  for (int i = 0; i < n; i++) ans[bid[i]] = aid[i];
  for (int i : ans) cout << i + 1 << " ";
  return 0;
}
