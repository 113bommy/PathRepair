#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
struct Data {
  int num;
  Data() : num(0) { ; }
  Data(int n) : num(n) { ; }
};
Data data[500000];
inline Data Merge(Data left, Data right) {
  return Data(left.num > right.num ? left.num : right.num);
}
struct SegmentTree {
  int n;
  SegmentTree(int N) : n(1 << N) {}
  void update(int pos, Data value) {
    data[pos] = value;
    while (pos < 2 * n - 1) {
      int l = pos, r = pos ^ 1;
      if (l > r) swap(l, r);
      pos = pos / 2 + n;
      data[pos] = Merge(data[l], data[r]);
    }
  }
  Data sub(int fr, int to, int node, int la, int ra) {
    if (ra <= fr || to <= la) return Data();
    if (fr <= la && ra <= to) return data[node];
    Data vl = sub(fr, to, (node - n) * 2 + 0, la, (la + ra) / 2);
    Data vr = sub(fr, to, (node - n) * 2 + 1, (la + ra) / 2, ra);
    return Merge(vl, vr);
  }
  Data query(int fr, int to) { return sub(fr, to, 2 * n - 2, 0, n); }
};
int N;
vector<pair<int, int> > v;
int dp[200000];
int cmp[200000][2];
int main(void) {
  cin >> N;
  v.resize(N);
  for (int i = 0; i < (int)(N); ++i) {
    int x, val;
    scanf("%d %d", &x, &val);
    v[i] = pair<int, int>(x, val);
  }
  sort(v.begin(), v.end());
  vector<int> vv(2 * N);
  for (int i = 0; i < (int)(N); ++i) vv[i] = v[i].first - v[i].second;
  for (int i = 0; i < (int)(N); ++i) vv[i + N] = v[i].first + v[i].second;
  sort(vv.begin(), vv.end());
  vv.erase(unique(vv.begin(), vv.end()), vv.end());
  for (int i = 0; i < (int)(N); ++i) {
    int lid = lower_bound(vv.begin(), vv.end(), v[i].first - v[i].second) -
              vv.begin();
    int rid = lower_bound(vv.begin(), vv.end(), v[i].first + v[i].second) -
              vv.begin();
    cmp[i][0] = lid;
    cmp[i][1] = rid;
  }
  SegmentTree st(2 * N);
  for (int i = 0; i < (int)(N); ++i) {
    dp[i] = st.query(0, cmp[i][0] + 1).num + 1;
    st.update(cmp[i][1], dp[i]);
  }
  cout << *max_element(dp, dp + N) << endl;
  return 0;
}
