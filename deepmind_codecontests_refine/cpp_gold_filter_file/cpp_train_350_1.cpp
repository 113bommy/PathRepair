#include <bits/stdc++.h>
using namespace std;
template <class t, class u>
void chmax(t& first, u second) {
  if (first < second) first = second;
}
template <class t, class u>
void chmin(t& first, u second) {
  if (second < first) first = second;
}
template <class t>
using vc = vector<t>;
template <class t>
using vvc = vc<vc<t>>;
using ll = long long;
using pi = pair<int, int>;
using vi = vc<int>;
using vvi = vvc<int>;
int topbit(int t) {
  assert(t > 0);
  return 31 - __builtin_clz(t);
}
struct X {
  int s;
  vvi buf;
  X(vi first) {
    s = 1;
    while (s < int((first).size())) s *= 2;
    buf.resize(2 * s);
    for (int i = int(1); i < int(2 * s); i++) buf[i] = vi(s >> topbit(i));
    for (int i = int(0); i < int(int((first).size())); i++)
      buf[s + i][0] = first[i];
    for (int i = int(s) - 1; i >= int(1); i--)
      merge((buf[2 * i]).begin(), (buf[2 * i]).end(), (buf[2 * i + 1]).begin(),
            (buf[2 * i + 1]).end(), buf[i].begin());
  }
  int in(int i, int second, int e) {
    return distance(lower_bound((buf[i]).begin(), (buf[i]).end(), second),
                    lower_bound((buf[i]).begin(), (buf[i]).end(), e));
  }
  int get(int second, int e, int b1, int e1) {
    int i = second + s;
    int j = e + s;
    int res = 0;
    while (i < j) {
      if (i & 1) res += in(i++, b1, e1);
      if (j & 1) res += in(--j, b1, e1);
      i /= 2;
      j /= 2;
    }
    return res;
  }
};
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  vi p(n);
  for (int i = int(0); i < int(n); i++) {
    cin >> p[i];
    p[i]--;
  }
  vi q(n);
  for (int i = int(0); i < int(n); i++) {
    cin >> q[i];
    q[i]--;
  }
  vi iq(n);
  for (int i = int(0); i < int(n); i++) iq[q[i]] = i;
  vi v(n);
  for (int i = int(0); i < int(n); i++) v[i] = iq[p[i]];
  X x(v);
  int m;
  cin >> m;
  int last = 0;
  auto f = [&](int z) -> int { return (z + last - 1) % n + 1; };
  for (int _ = int(0); _ < int(m); _++) {
    int first, second, c, d;
    cin >> first >> second >> c >> d;
    int l1 = min(f(first), f(second)) - 1;
    int r1 = max(f(first), f(second));
    int l2 = min(f(c), f(d)) - 1;
    int r2 = max(f(c), f(d));
    last = x.get(l1, r1, l2, r2);
    cout << last << '\n';
    last++;
  }
}
