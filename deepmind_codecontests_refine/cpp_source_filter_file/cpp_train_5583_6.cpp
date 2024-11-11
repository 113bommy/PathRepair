#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<int, int>;
using vb = vector<bool>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vii = vector<ii>;
struct Comp {
  Comp(const vi& s) : min_s{s}, max_s{s}, size(1){};
  bool operator<(const Comp& other) const {
    bool less = true;
    for (int i = 0, _i = (static_cast<int>((max_s).size())); i < _i; ++i)
      if (max_s[i] > other.min_s[i]) return false;
    return true;
  }
  vi min_s, max_s;
  int size;
};
void merge(set<Comp>::iterator a, set<Comp>::iterator b, Comp& c) {
  for (; a != b; ++a) {
    c.size += a->size;
    for (int i = 0, _i = (static_cast<int>((c.min_s).size())); i < _i; ++i) {
      c.min_s[i] = min(c.min_s[i], a->min_s[i]);
      c.max_s[i] = max(c.min_s[i], a->min_s[i]);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, k;
  cin >> n >> k;
  vi s(k);
  for (int i = 0, _i = (k); i < _i; ++i) cin >> s[i];
  set<Comp> comps{{s}};
  cout << 1 << endl;
  for (int i = 0, _i = (n - 1); i < _i; ++i) {
    for (int i = 0, _i = (k); i < _i; ++i) cin >> s[i];
    Comp c(s);
    auto a = comps.lower_bound(c), b = comps.upper_bound(c);
    if (a != b) {
      merge(a, b, c);
      comps.erase(a, b);
    }
    comps.insert(c);
    cout << comps.rbegin()->size << endl;
  }
}
