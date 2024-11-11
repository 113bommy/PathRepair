#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 30;

struct SegNode
{
  int v;

  SegNode(int v) : v(v) {}

  SegNode operator*(const SegNode &r) const
  {
    return (v < r.v ? *this : r);
  }
} e(INF);

struct SegmentTree
{
  int sz;
  vector< SegNode > seg;

  SegmentTree(int n)
  {
    sz = 1;
    while(sz < n) sz <<= 1;
    seg.assign(2 * sz - 1, e);
  }

  void update(int k, const SegNode &x)
  {
    k += sz - 1;
    seg[k] = x;
    while(k > 0) {
      k = (k - 1) >> 1;
      seg[k] = seg[2 * k + 1] * seg[2 * k + 2];
    }
  }

  SegNode query(int a, int b, int k, int l, int r)
  {
    if(a >= r || b <= l) return (e);
    if(a <= l && r <= b) return (seg[k]);
    return (query(a, b, 2 * k + 1, l, (l + r) >> 1) * query(a, b, 2 * k + 2, (l + r) >> 1, r));
  }

  SegNode query(int a, int b)
  {
    return (query(a, b, 0, 0, sz));
  }
};

int main()
{
  int N, K;
  string S, T;

  cin >> N >> K;

  cin >> S;
  cin >> T;

  vector< int > sweep(N + 1);
  for(int i = 0; i + 1 < N; i++) {
    if(T[i] != T[i + 1]) sweep[i + 1] = 1;
    sweep[i + 1] += sweep[i];
  }

  SegmentTree seg(N);
  vector< int > dp(N + 1, INF);
  dp[0] = 0;
  seg.update(0, 0);
  for(int i = 1; i <= N; i++) {
    dp[i] = min(dp[i - 1] + (S[i - 1] != T[i - 1]), (seg.query(i - K, i - 1).v + 3 + sweep[i - 1]) / 2);
    seg.update(i, dp[i] * 2 - sweep[i]);
  }
  cout << dp.back() << endl;
}