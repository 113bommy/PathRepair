#include <bits/stdc++.h>
using namespace std;
template <typename TH>
void _dbg(const char* sdbg, TH h) {
  cerr << sdbg << "=" << h << "\n";
}
template <typename TH, typename... TA>
void _dbg(const char* sdbg, TH h, TA... t) {
  while (*sdbg != ',') cerr << *sdbg++;
  cerr << "=" << h << ",";
  _dbg(sdbg + 1, t...);
}
template <class C>
void mini(C& a4, C b4) {
  a4 = min(a4, b4);
}
template <class C>
void maxi(C& a4, C b4) {
  a4 = max(a4, b4);
}
template <class T1, class T2>
ostream& operator<<(ostream& out, pair<T1, T2> pair) {
  return out << "(" << pair.first << ", " << pair.second << ")";
}
template <class A, class B, class C>
struct Triple {
  A first;
  B second;
  C third;
  bool operator<(const Triple& t) const {
    if (first != t.first) return first < t.first;
    if (second != t.second) return second < t.second;
    return third < t.third;
  }
};
template <class T>
void ResizeVec(T&, vector<long long>) {}
template <class T>
void ResizeVec(vector<T>& vec, vector<long long> sz) {
  vec.resize(sz[0]);
  sz.erase(sz.begin());
  if (sz.empty()) {
    return;
  }
  for (T& v : vec) {
    ResizeVec(v, sz);
  }
}
template <class A, class B, class C>
ostream& operator<<(ostream& out, Triple<A, B, C> t) {
  return out << "(" << t.first << ", " << t.second << ", " << t.third << ")";
}
template <class T>
ostream& operator<<(ostream& out, vector<T> vec) {
  out << "(";
  for (auto& v : vec) out << v << ", ";
  return out << ")";
}
bool CmpX(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second < b.second;
}
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  long long n, m, d;
  cin >> d >> n >> m;
  vector<pair<long long, long long> > stations;
  for (long long i = (1); i <= (m); ++i) {
    long long x, p;
    cin >> x >> p;
    stations.push_back({p, x});
  }
  sort((stations).begin(), (stations).end(), CmpX);
  if (stations[0].second > n || d - stations.back().second > n) {
    cout << "-1\n";
    return 0;
  }
  for (long long i = 0; i < (((long long)(stations).size()) - 1); ++i) {
    if (stations[i + 1].second - stations[i].second > n) {
      cout << "-1\n";
      return 0;
    }
  }
  sort((stations).begin(), (stations).end());
  set<long long> used;
  used.insert(0);
  used.insert(d);
  long long res = 0;
  for (auto stat : stations) {
    used.insert(stat.second);
    auto it = used.find(stat.second);
    it--;
    long long got = max(0ll, n - (stat.second - *it));
    it++;
    it++;
    long long need = max(*it - stat.second - got, 0ll);
    res += stat.first * need;
  }
  cout << res << endl;
  return 0;
}
