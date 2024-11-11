#include <bits/stdc++.h>
#pragma GCC optimize("O3")
#pragma GCC target("sse4")
using namespace std;
struct SumSegmentTree {
  int sz;
  long long* tree;
  SumSegmentTree(int s) {
    sz = 1 << (int)ceil(log2(s));
    tree = new long long[2 * sz];
    memset(tree, 0, 2 * sz * sizeof(long long));
  }
  SumSegmentTree(int s, long long* st) {
    sz = 1 << (int)ceil(log2(s));
    tree = new long long[2 * sz];
    memset(tree, 0, 2 * sz * sizeof(long long));
    for (int i = 0; i < (s); i++) {
      tree[i + sz] = st[i];
    }
    for (int ind = (sz)-1; ind >= (1); ind--) {
      tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
    }
  }
  void add(int ind, long long x) {
    ind += sz;
    tree[ind] += x;
    for (ind /= 2; ind >= 1; ind /= 2) {
      tree[ind] = tree[2 * ind] + tree[2 * ind + 1];
    }
  }
  long long sum(int a, int b) {
    a += sz;
    b += sz;
    long long s = 0;
    while (a <= b) {
      if (a % 2 == 1) s += tree[a++];
      if (b % 2 == 0) s += tree[b--];
      a /= 2;
      b /= 2;
    }
    return s;
  }
};
long long n, m;
long long v, e;
SumSegmentTree s(1000005);
pair<long long, pair<long long, long long>> hr[100005];
pair<long long, pair<long long, long long>> vr[100005];
pair<pair<long long, long long>, long long> sw[300015];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (int i = 0; i < (n); i++) {
    long long y, lx, rx;
    cin >> y >> lx >> rx;
    hr[i] = make_pair(y, make_pair(lx, rx));
  }
  for (int i = 0; i < (m); i++) {
    long long x, ly, ry;
    cin >> x >> ly >> ry;
    vr[i] = make_pair(x, make_pair(ly, ry));
  }
  hr[n] = make_pair(0, make_pair(0, 1000000));
  hr[n + 1] = make_pair(1000000, make_pair(0, 1000000));
  vr[n] = make_pair(0, make_pair(0, 1000000));
  vr[n + 1] = make_pair(1000000, make_pair(0, 1000000));
  long long ind = 0;
  for (int i = 0; i < (n + 2); i++) {
    sw[ind] = make_pair(make_pair(hr[i].second.first, 0), i);
    ind++;
    sw[ind] = make_pair(make_pair(hr[i].second.second, 2), i);
    ind++;
  }
  for (int i = 0; i < (m + 2); i++) {
    sw[ind] = make_pair(make_pair(vr[i].first, 1), i);
    ind++;
  }
  sort(sw, sw + 2 * n + m + 6);
  long long ans = 0;
  for (int i = 0; i < (2 * n + m + 6); i++) {
    pair<pair<long long, long long>, long long> next = sw[i];
    if (sw[i].first.second == 0) {
      s.add(hr[sw[i].second].first, 1);
    } else if (sw[i].first.second == 2) {
      s.add(hr[sw[i].second].first, -1);
    } else {
      ans +=
          s.sum(vr[sw[i].second].second.first, vr[sw[i].second].second.second);
    }
  }
  v = 2 * (n + m + 4) + ans;
  e = (n + m + 4) + 2 * ans;
  v -= 2 * (n + m);
  e -= 2 * (n + m);
  cout << (1 + e - v) << "\n";
  return 0;
}
