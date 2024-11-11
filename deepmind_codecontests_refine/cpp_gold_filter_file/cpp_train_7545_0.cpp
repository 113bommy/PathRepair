#include <bits/stdc++.h>
using namespace std;
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
const long long N = 1e5 + 5;
long long deg[N], is_bad[N], bad_neis[N], is_frt[N];
vector<long long> slo[N];
int main() {
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(10);
  if (0) cout << fixed << setprecision(10);
  cin.tie(0);
  double beg_clock = 1.0 * clock() / CLOCKS_PER_SEC;
  long long n, m, k;
  cin >> n >> m >> k;
  ;
  vector<long long> strt;
  for (long long i = (1); i <= (k); ++i) {
    long long c;
    cin >> c;
    ;
    strt.push_back(c);
    is_frt[c] = 1;
  }
  for (long long i = (1); i <= (m); ++i) {
    long long a, b;
    cin >> a >> b;
    ;
    slo[a].push_back(b);
    slo[b].push_back(a);
    deg[a]++;
    deg[b]++;
  }
  vector<long long> best_set;
  long double kl = 0, kp = 1;
  for (long long tr = 0; tr < (80); ++tr) {
    long double aktc = (kl + kp) / 2;
    vector<long long> que = strt;
    for (long long i = (1); i <= (n); ++i) {
      bad_neis[i] = 0;
      is_bad[i] = 0;
    }
    for (long long ii = 0; ii < ((long long)(que).size()); ii++) {
      long long v = que[ii];
      is_bad[v] = 1;
      for (auto nei : slo[v]) {
        bad_neis[nei]++;
        if (is_bad[nei] == 0 && !is_frt[nei] &&
            (1 - aktc) * deg[nei] < bad_neis[nei]) {
          is_bad[nei] = 1;
          que.push_back(nei);
        }
      }
    }
    if (((long long)(que).size()) < n) {
      kl = aktc;
      best_set.clear();
      for (long long i = (1); i <= (n); ++i) {
        if (!is_bad[i]) {
          best_set.push_back(i);
        }
      }
    } else {
      kp = aktc;
    }
  }
  cout << ((long long)(best_set).size()) << endl;
  for (auto v : best_set) {
    cout << v << " ";
  }
  cout << endl;
  return 0;
}
