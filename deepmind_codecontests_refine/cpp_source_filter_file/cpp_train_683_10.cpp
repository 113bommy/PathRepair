#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e9 + 7, N = 200000, BASE = 130;
long long MOD(long long x) {
  x = x % INF;
  if (x < 0) x += INF;
  return x;
}
struct pair_ {
  long long f, s, ind;
};
string s;
long long n, m;
vector<long long> hash_, power;
void init() {
  power.resize(n);
  power[0] = 1;
  for (int i = 1; i < n; i++) {
    power[i] = MOD(power[i - 1] * BASE);
  }
  hash_.resize(n);
  hash_[0] = s[0];
  for (int i = 1; i < n; i++) {
    hash_[i] = MOD(hash_[i - 1] + s[i] * power[i]);
  }
}
bool check(long long x, long long y, long long d) {
  if (x > y) {
    swap(x, y);
  }
  long long up = y - x;
  long long f = hash_[x + d];
  if (x) {
    f -= hash_[x - 1];
  }
  long long s = hash_[y + d];
  if (y) {
    s -= hash_[y - 1];
  }
  if (MOD(f * power[up]) == MOD(s)) {
    return true;
  }
  return false;
}
void program() {
  cin >> s;
  s += (int)31;
  n = s.size();
  vector<int> ar(n);
  for (int i = 0; i < n; i++) {
    ar[i] = (int)s[i];
  }
  int len = 1;
  while (len < n) {
    vector<pair_> tmp(n), tmp_(n);
    for (int i = 0; i < n; i++) {
      pair_ p;
      p.f = ar[i];
      p.s = ar[(i + len) % n];
      p.ind = i;
      tmp[i] = p;
    }
    map<pair<int, int>, int> sorted;
    vector<int> cnt(N), go(N);
    for (int i = 0; i < n; i++) {
      cnt[tmp[i].s]++;
    }
    for (int i = 1; i < N; i++) {
      go[i] = go[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      int num = tmp[i].s;
      tmp_[go[num]] = tmp[i];
      go[num]++;
    }
    cnt.assign(N, 0);
    go.assign(N, 0);
    for (int i = 0; i < n; i++) {
      cnt[tmp_[i].f]++;
    }
    for (int i = 1; i < N; i++) {
      go[i] = go[i - 1] + cnt[i - 1];
    }
    for (int i = 0; i < n; i++) {
      int num = tmp_[i].f;
      tmp[go[num]] = tmp_[i];
      go[num]++;
    }
    int count = 1;
    sorted[make_pair(tmp[0].f, tmp[0].s)] = 0;
    for (int i = 1; i < n; i++) {
      if (tmp[i].f != tmp[i - 1].f || tmp[i].s != tmp[i - 1].s) {
        sorted[make_pair(tmp[i].f, tmp[i].s)] = count;
        count++;
      }
    }
    for (int i = 0; i < n; i++) {
      pair_ p = tmp[i];
      int num = sorted[make_pair(p.f, p.s)];
      ar[p.ind] = num;
    }
    len *= 2;
  }
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    arr[ar[i]] = i;
  }
  init();
  vector<pair<int, int>> st;
  long long tmp = 0, ans = 0;
  st.push_back(make_pair(0, 0));
  vector<int> cnt(n);
  for (int i = 0, j = 1; j < n; i++, j++) {
    long long p = arr[i], q = arr[j];
    long long l = -1, r = min(n - p, n - q);
    while (l + 1 < r) {
      long long mid = (l + r) / 2;
      bool if_ = check(p, q, mid);
      if (if_) {
        l = mid;
      } else {
        r = mid;
      }
    }
    cnt[p] = max((long long)cnt[p], r);
    cnt[q] = max((long long)cnt[q], r);
    if (r > tmp) {
      tmp = r;
      st.push_back(make_pair(tmp, i));
    }
    while (r < st.back().first) {
      auto b = st.back();
      auto a = (long long)st[st.size() - 2].first;
      int num = (i - b.second + 1);
      ans += num * num * (b.first - max(a, r));
      st.pop_back();
      tmp = a;
      if (r > a) {
        tmp = r;
        st.push_back(make_pair(r, b.second));
      }
    }
  }
  int r = 0;
  while (r < st.back().first) {
    auto b = st.back();
    auto a = st[st.size() - 2];
    long long num = (n - 1 - b.second + 1);
    ans += num * num * (b.first - a.first);
    st.pop_back();
    tmp = a.first;
  }
  for (int i = 0; i < n; i++) {
    ans += n - arr[i] - cnt[i] - 1;
  }
  cout << ans << '\n';
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    program();
  }
}
