#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void check_max(T& actual, T check) {
  if (actual < check) {
    actual = check;
  }
}
template <class T>
inline void check_min(T& actual, T check) {
  if (actual > check) {
    actual = check;
  }
}
const double EPS = 1e-9;
const int IINF = 1000000000;
const double PI = acos(-1.0);
const long long LINF = 6000000000000000000LL;
const int maxM = (int)1e5 + 20;
int m, x[maxM], y[maxM], u[maxM];
map<pair<int, int>, int> mapping;
set<int> under[maxM], upon[maxM];
long long MOD = (int)1e9 + 9;
class Comparator {
 public:
  bool operator()(int a, int b) { return a > b; }
};
int main() {
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &x[i], &y[i]);
    mapping[make_pair(x[i], y[i])] = i;
  }
  for (int i = 0; i < m; ++i) {
    if (y[i] != 0) {
      if (mapping.find(make_pair(x[i] - 1, y[i] - 1)) != mapping.end()) {
        under[i].insert(mapping[make_pair(x[i] - 1, y[i] - 1)]);
      }
      if (mapping.find(make_pair(x[i], y[i - 1])) != mapping.end()) {
        under[i].insert(mapping[make_pair(x[i], y[i] - 1)]);
      }
      if (mapping.find(make_pair(x[i] + 1, y[i] - 1)) != mapping.end()) {
        under[i].insert(mapping[make_pair(x[i] + 1, y[i] - 1)]);
      }
    }
    if (mapping.find(make_pair(x[i] - 1, y[i] + 1)) != mapping.end()) {
      upon[i].insert(mapping[make_pair(x[i] - 1, y[i] + 1)]);
    }
    if (mapping.find(make_pair(x[i], y[i] + 1)) != mapping.end()) {
      upon[i].insert(mapping[make_pair(x[i], y[i] + 1)]);
    }
    if (mapping.find(make_pair(x[i] + 1, y[i] + 1)) != mapping.end()) {
      upon[i].insert(mapping[make_pair(x[i] + 1, y[i] + 1)]);
    }
  }
  set<int> safe, dangerous;
  for (int i = 0; i < m; ++i) {
    bool ok = true;
    for (auto it = upon[i].begin(); it != upon[i].end(); ++it) {
      if (((int)under[*it].size()) == 1) {
        ok = false;
      }
    }
    if (ok) {
      safe.insert(i);
    } else {
      dangerous.insert(i);
    }
  }
  long long answer = 0;
  for (int it = 0; it < m; ++it) {
    assert(!safe.empty());
    int ind;
    if (it & 1) {
      ind = *safe.begin();
    } else {
      ind = *safe.rbegin();
    }
    safe.erase(ind);
    u[ind] = 1;
    ;
    answer = (answer * m + ind) % MOD;
    for (auto it = upon[ind].begin(); it != upon[ind].end(); ++it) {
      under[*it].erase(ind);
      if (((int)under[*it].size()) == 1) {
        safe.erase(*under[*it].begin());
        if (!u[*under[*it].begin()]) {
          dangerous.insert(*under[*it].begin());
        }
      }
    }
    for (auto it = under[ind].begin(); it != under[ind].end(); ++it) {
      upon[*it].erase(ind);
      bool ok = true;
      for (auto it1 = upon[*it].begin(); it1 != upon[*it].end(); ++it1) {
        if (((int)under[*it1].size()) == 1) {
          ok = false;
        }
      }
      if (ok) {
        dangerous.erase(*it);
        if (!u[*it]) {
          safe.insert(*it);
        }
      } else {
        if (!u[*it]) {
          dangerous.insert(*it);
        }
      }
    }
  }
  printf("%lld\n", answer);
  return 0;
}
