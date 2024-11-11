#include <bits/stdc++.h>
using namespace std;
template <class T, class U>
void ckmin(T &a, U b) {
  a = min(a, b);
}
template <class T, class U>
void ckmax(T &a, U b) {
  a = max(a, b);
}
int N, M, K, Q;
pair<int, int> arr[200013];
bitset<200013> ans;
vector<pair<int, int> > pos[200013];
pair<pair<int, int>, pair<int, int> > queries[200013];
vector<pair<pair<int, int>, pair<int, int> > > quer[200013];
vector<pair<pair<int, int>, pair<int, int> > > events[200013];
vector<int> rooks[200013];
int seg[3 * 200013];
void build(int w, int L, int R) {
  seg[w] = -1;
  if (L == R) return;
  int mid = (L + R) >> 1;
  build(w << 1, L, mid);
  build(w << 1 | 1, mid + 1, R);
}
void update(int w, int L, int R, int a, int v) {
  if (L == R) {
    seg[w] = v;
    return;
  }
  int mid = (L + R) >> 1;
  if (a <= mid) {
    update(w << 1, L, mid, a, v);
  } else {
    update(w << 1 | 1, mid + 1, R, a, v);
  }
  seg[w] = min(seg[w << 1 | 1], seg[w << 1]);
}
int query(int w, int L, int R, int a, int b) {
  if (a <= L && R <= b) {
    return seg[w];
  }
  int mid = (L + R) >> 1;
  if (b <= mid) {
    return query(w << 1, L, mid, a, b);
  }
  if (a > mid) {
    return query(w << 1 | 1, mid + 1, R, a, b);
  }
  return min(query(w << 1, L, mid, a, b), query(w << 1 | 1, mid + 1, R, a, b));
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> M >> K >> Q;
  N = max(N, M);
  for (auto i = (0); i < (K); i++) {
    cin >> arr[i].first >> arr[i].second;
    arr[i].first--;
    arr[i].second--;
  }
  for (auto i = (0); i < (Q); i++) {
    cin >> queries[i].first.first >> queries[i].second.first >>
        queries[i].first.second >> queries[i].second.second;
    queries[i].first.first--;
    queries[i].first.second--;
    queries[i].second.first--;
    queries[i].second.second--;
  }
  for (auto i = (0); i < (K); i++) {
    rooks[arr[i].first].push_back(arr[i].second);
  }
  for (auto i = (0); i < (Q); i++) {
    events[queries[i].first.second].push_back(
        {queries[i].second, {queries[i].first.first, i}});
  }
  build(1, 0, N - 1);
  for (auto i = (0); i < (N); i++) {
    for (int x : rooks[i]) {
      update(1, 0, N - 1, x, i);
    }
    for (auto p : events[i]) {
      int l = p.first.first, r = p.first.second, x = p.second.first,
          qid = p.second.second;
      if (query(1, 0, N - 1, l, r) >= x) {
        ans[qid] = true;
      }
    }
    rooks[i].clear();
    events[i].clear();
  }
  for (auto i = (0); i < (K); i++) {
    rooks[arr[i].second].push_back(arr[i].first);
  }
  for (auto i = (0); i < (Q); i++) {
    events[queries[i].second.second].push_back(
        {queries[i].first, {queries[i].second.first, i}});
  }
  build(1, 0, N - 1);
  for (auto i = (0); i < (N); i++) {
    for (int x : rooks[i]) {
      update(1, 0, N - 1, x, i);
    }
    for (auto p : events[i]) {
      int l = p.first.first, r = p.first.second, x = p.second.first,
          qid = p.second.second;
      if (query(1, 0, N - 1, l, r) >= x) {
        ans[qid] = true;
      }
    }
    rooks[i].clear();
    events[i].clear();
  }
  for (auto i = (0); i < (Q); i++) {
    cout << (ans[i] ? "YES" : "NO") << '\n';
  }
}
