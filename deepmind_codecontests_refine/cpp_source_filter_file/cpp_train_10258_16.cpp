#include <bits/stdc++.h>
using namespace std;
template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &vec) {
  for (auto &v : vec) is >> v;
  return is;
}
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  for (int i = 0; i < vec.size(); i++) {
    os << vec[i];
    if (i + 1 != vec.size()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const set<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_set<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const multiset<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T>
ostream &operator<<(ostream &os, const unordered_multiset<T> &st) {
  for (auto itr = st.begin(); itr != st.end(); ++itr) {
    os << *itr;
    auto titr = itr;
    if (++titr != st.end()) os << " ";
  }
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const map<T1, T2> &mp) {
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    os << "(" << itr->first << ", " << itr->second << ")";
    auto titr = itr;
    if (++titr != mp.end()) os << " ";
  }
  return os;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const unordered_map<T1, T2> &mp) {
  for (auto itr = mp.begin(); itr != mp.end(); ++itr) {
    os << "(" << itr->first << ", " << itr->second << ")";
    auto titr = itr;
    if (++titr != mp.end()) os << " ";
  }
  return os;
}
using ll = long long int;
using P = pair<int, int>;
const int inf = 1e9;
const ll linf = 1LL << 50;
const double EPS = 1e-10;
const int mod = 1000000007;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, -1, 0, 1};
struct fast_io {
  fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(20);
  }
} fast_io_;
int main(int argc, char const *argv[]) {
  ll n, m;
  cin >> n >> m;
  m *= 2;
  ll t;
  cin >> t;
  t *= 2;
  vector<ll> x(n);
  vector<ll> d(n);
  for (int i = (0); i < (n); ++i) {
    cin >> x[i];
    x[i] *= 2;
    x[i] %= m;
    string c;
    cin >> c;
    d[i] = (c == "L" ? -1 : 1);
  }
  vector<int> e(n);
  for (int i = (0); i < (n); ++i) e[i] = i;
  sort((e).begin(), (e).end(), [&](int i, int j) { return x[i] < x[j]; });
  vector<int> tr(n);
  for (int i = (0); i < (n); ++i) tr[e[i]] = i;
  vector<ll> res(n);
  for (int i_ = (0); i_ < (n); ++i_) {
    int i = e[i_];
    res[i_] = (x[i] + d[i] * t) % m;
    if (res[i_] < 0) res[i_] += m;
  }
  ll curr = 0;
  if (d[e[0]] == 1) {
    for (int k = (1); k < (n); ++k) {
      if (d[e[k]] == -1 && (x[e[k]] - x[e[0]]) / 2 <= t) {
        curr += (t - (x[e[k]] - x[e[0]]) / 2) / (m / 2) + 1;
      }
    }
  } else {
    x[e[0]] += m;
    for (int k = (1); k < (n); ++k) {
      if (d[e[k]] == 1 && (x[e[0]] - x[e[k]]) / 2 <= t) {
        curr += (t - (x[e[0]] - x[e[k]]) / 2) / (m / 2) + 1;
      }
    }
    curr = (n - curr) % n;
    if (curr < 0) curr += n;
  }
  curr %= n;
  vector<pair<ll, int>> v(n);
  for (int i = (0); i < (n); ++i) v[i] = make_pair(res[i], i);
  sort((v).begin(), (v).end(), [&](pair<ll, int> x, pair<ll, int> y) {
    if (x.first != y.first) return x.first < y.first;
    if (d[e[x.second]] == 0) return true;
    return false;
  });
  int at = 0;
  for (int i = (0); i < (n); ++i)
    if (v[i].second == 0) at = i;
  for (int i = (0); i < (n); ++i) {
    res[i] = v[(at + i) % n].first;
  }
  vector<ll> tres = res;
  for (int i = (0); i < (n); ++i) {
    res[i] = tres[(i - curr + n) % n];
  }
  tres = res;
  for (int i = (0); i < (n); ++i) res[i] = tres[tr[i]];
  for (int i = (0); i < (n); ++i) {
    if (res[i] < 0) res[i] += m;
  }
  for (int i = (0); i < (n); ++i) {
    res[i] /= 2;
    if (res[i] == 0) res[i] = (m / 2);
  }
  cout << res << endl;
  return 0;
}
