#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  if (a > b) a = b;
}
template <class T, class U>
void ckmax(T &a, U b) {
  if (a < b) a = b;
}
int N, Q;
int arr[300013];
vector<pair<int, int> > queries[300013];
int ans[300013];
vector<int> compress;
struct segtree {
  int seg[300013];
  void update(int w, int L, int R, int a, int v) {
    if (L == R) {
      ckmin(seg[w], v);
      return;
    }
    int mid = (L + R) >> 1;
    if (a <= mid)
      update(w << 1, L, mid, a, v);
    else
      update(w << 1 | 1, mid + 1, R, a, v);
    seg[w] = min(seg[w << 1], seg[w << 1 | 1]);
  }
  int query(int w, int L, int R, int a, int b) {
    if (a <= L && R <= b) {
      return seg[w];
    }
    int mid = (L + R) >> 1;
    if (b <= mid) return query(w << 1, L, mid, a, b);
    if (mid < a) return query(w << 1 | 1, mid + 1, R, a, b);
    return min(query(w << 1, L, mid, a, b),
               query(w << 1 | 1, mid + 1, R, a, b));
  }
};
vector<pair<int, int> > mq;
segtree S[2];
void solve() {
  compress.clear();
  for (auto i = (0); i < (N); i++) {
    compress.push_back(arr[i]);
  }
  sort((compress).begin(), (compress).end());
  compress.erase(unique((compress).begin(), (compress).end()), compress.end());
  for (auto i = (0); i < ((1 << (33 - __builtin_clz(N)))); i++) {
    S[0].seg[i] = 1000000007;
    S[1].seg[i] = 1000000007;
  }
  for (auto i = (0); i < (N); i++) {
    int x = arr[i];
    while (!mq.empty() && mq.back().first < x) {
      mq.pop_back();
    }
    if (!mq.empty()) {
      int dif = mq.back().first - x, pos = mq.back().second;
      S[0].update(1, 0, N - 1, pos, dif);
      while (dif) {
        dif = (dif - 1) / 2;
        int lo = lower_bound((compress).begin(), (compress).end(), x) -
                 compress.begin(),
            hi = upper_bound((compress).begin(), (compress).end(), x + dif) -
                 compress.begin() - 1;
        if (lo > hi) break;
        pos = -S[1].query(1, 0, N - 1, lo, hi);
        if (pos == -1000000007) break;
        dif = arr[pos] - x;
        S[0].update(1, 0, N - 1, pos, dif);
      }
      if (mq.back().first == x) mq.pop_back();
    }
    mq.push_back({x, i});
    int ind = lower_bound((compress).begin(), (compress).end(), arr[i]) -
              compress.begin();
    S[1].update(1, 0, N - 1, ind, -i);
    for (auto p : queries[i]) {
      ckmin(ans[p.second], S[0].query(1, 0, N - 1, p.first, i));
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (auto i = (0); i < (N); i++) {
    cin >> arr[i];
  }
  cin >> Q;
  for (auto i = (0); i < (Q); i++) {
    int l, r;
    cin >> l >> r;
    l--;
    r--;
    queries[r].push_back({l, i});
    ans[i] = 1000000007;
  }
  solve();
  for (auto i = (0); i < (N); i++) {
    arr[i] = -arr[i];
  }
  solve();
  for (auto i = (0); i < (Q); i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}
