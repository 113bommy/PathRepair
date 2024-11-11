#include <bits/stdc++.h>
using namespace std;
template <class T>
struct rge {
  T b, e;
};
template <class T>
rge<T> range(T i, T j) {
  return rge<T>{i, j};
};
template <class A, class B>
ostream &operator<<(ostream &os, pair<A, B> p) {
  return os << "(" << p.first << ", " << p.second << ")";
}
template <class T>
ostream &operator<<(ostream &os, rge<T> d) {
  os << "[";
  for (auto it = d.b; it != d.e; it++) os << (it == d.b ? "" : ", ") << *it;
  return os << "]";
}
const int N = 5e5 + 5;
const int inf = 1e9 + 7;
template <class T>
struct fenwick {
  vector<T> fenw;
  fenwick(int _n = 0) { fenw.resize(_n + 5, {}); }
  void update(int sx, T v) {
    for (int x = (sx); x <= ((int)(fenw).size() - 1); x += (+(x & -x))) {
      fenw[x] += v;
    }
  }
  T query(int sx) {
    T v = {};
    for (int x = (sx); x >= (1); x += (-(x & -x))) {
      v += fenw[x];
    }
    return v;
  }
};
int mp[N];
multiset<long long> eels;
queue<int> qu;
fenwick<long long> sum(N);
int n, m;
void add(int x) {
  int i = lower_bound(mp, mp + m, x) - mp;
  sum.update(i, x);
  eels.insert(1LL * x);
}
void rem(int x) {
  int i = lower_bound(mp, mp + m, x) - mp;
  sum.update(i, -x);
  eels.erase(eels.find(1LL * x));
}
long long danger(int x) {
  int i = lower_bound(mp, mp + m, x) - mp;
  return sum.query(i - 1);
}
int fight() {
  if (eels.empty()) {
    return 0;
  }
  long long x = 0;
  int tot = (int)(eels).size();
  while (x < inf) {
    auto it = eels.upper_bound(2LL * x);
    if (it == eels.end()) {
      break;
    }
    if (2 * danger(*it) < *it) {
      tot--;
    }
    x = danger(*it) + *it;
  }
  return tot;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0), cout.precision(15);
  cin >> n;
  for (int i = (0); i <= ((n)-1); i += (+1)) {
    char c;
    int x;
    cin >> c >> x;
    qu.push((c == '+' ? +1 : -1) * x);
    mp[i] = x;
  }
  mp[n] = -inf;
  sort(mp, mp + n + 1);
  m = unique(mp, mp + n + 1) - mp;
  while (!qu.empty()) {
    int x = qu.front();
    qu.pop();
    if (x > 0) {
      add(x);
    } else {
      rem(-x);
    }
    cout << fight() << '\n';
  }
  return 0;
}
