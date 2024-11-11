#include <bits/stdc++.h>
using namespace std;
long long const N = 1e5 + 20;
long long n, a[N];
map<long long, long long> mp;
vector<long long> vec;
string s[N];
struct node {
  long long num, cnt[5];
} seg[N << 2];
inline void update(const long long& v, const long long& lc,
                   const long long& rc) {
  for (long long i = 0; i < 5; i++)
    seg[v].cnt[i] = seg[lc].cnt[i] + seg[rc].cnt[(i + 5 - seg[lc].num) % 5];
  seg[v].num = seg[lc].num + seg[rc].num;
}
void modify(long long idx, long long val, long long v = 1, long long s = 0,
            long long e = n) {
  if (s + 1 == e) {
    seg[v].cnt[0] += val;
    if (val > 0)
      seg[v].num++;
    else
      seg[v].num--;
    seg[v].num = (seg[v].num + 5) % 5;
    return;
  }
  long long mid = (s + e) >> 1, lc = v << 1, rc = lc | 1;
  if (idx < mid)
    modify(idx, val, lc, s, mid);
  else
    modify(idx, val, rc, mid, e);
  update(v, lc, rc);
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> s[i];
    if (s[i] != "sum") {
      cin >> a[i];
      vec.push_back(a[i]);
    }
  }
  sort(vec.begin(), vec.end());
  vec.resize(unique(vec.begin(), vec.end()) - vec.begin());
  for (long long i = 0; i < (long long)vec.size(); i++) mp[vec[i]] = i;
  for (long long i = 0; i < n; i++) {
    if (s[i] == "add")
      modify(mp[a[i]], a[i]);
    else if (s[i] == "del")
      modify(mp[a[i]], -a[i]);
    else
      cout << seg[1].cnt[2] << '\n';
  }
}
