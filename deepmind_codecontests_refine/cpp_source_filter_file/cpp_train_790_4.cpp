#include <bits/stdc++.h>
using namespace std;
template <class c>
struct rge {
  c b, e;
};
template <class c>
rge<c> range(c i, c j) {
  return rge<c>{i, j};
}
template <class c>
auto dud(c* x) -> decltype(cerr << *x, 0);
template <class c>
char dud(...);
struct debug {
  template <class c>
  debug& operator<<(const c&) {
    return *this;
  }
};
using ll = long long;
using ld = long double;
constexpr int nax = 1000 * 1000 + 105;
constexpr int infty = 1000 * 1000 * 1000 + 5;
constexpr int mod = 1000 * 1000 * 1000 + 7;
set<string> nazwy;
string Unique() {
  while (true) {
    string s;
    for (int i = 0; i < 6; i++) {
      s.push_back('a' + rand() % ('z' - 'a' + 1));
    }
    if (nazwy.insert(s).second) {
      return s;
    }
  }
}
int n, m;
string name[nax];
bool test[nax];
bool zazn[nax];
char buf[105];
map<string, int> odwr;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", buf);
    name[i] = buf;
    int x;
    scanf("%d", &x);
    test[i] = x;
    if (test[i]) m++;
    nazwy.insert(to_string(i));
    nazwy.insert(name[i]);
    odwr[name[i]] = i;
  }
  set<string> puste[2], zle[2], kolejka[2];
  for (int i = 1; i <= n; i++) {
    int x = odwr[to_string(i)];
    if (x == 0) {
      puste[i <= m].insert(to_string(i));
    } else {
      assert(1 <= x and x <= n);
      zazn[x] = true;
      if ((x <= m) == test[x]) {
      } else {
        zle[x <= m].insert(to_string(i));
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!zazn[i]) {
      kolejka[test[i]].insert(name[i]);
    }
  }
  vector<pair<string, string>> result;
  debug() << " ["
          << "puste[0]"
             ": "
          << (puste[0])
          << "] "
             " ["
          << "puste[1]"
             ": "
          << (puste[1])
          << "] "
             " ["
          << "zle[0]"
             ": "
          << (zle[0])
          << "] "
             " ["
          << "zle[1]"
             ": "
          << (zle[1])
          << "] "
             " ["
          << "kolejka[0]"
             ": "
          << (kolejka[0])
          << "] "
             " ["
          << "kolejka[1]"
             ": "
          << (kolejka[1]) << "] ";
  if (puste[0].empty() and puste[1].empty() and
      (!zle[0].empty() or !zle[1].empty())) {
    const int q = (zle[0].empty());
    const string s = Unique();
    result.emplace_back(*zle[q].begin(), s);
    puste[q].insert(*zle[q].begin());
    zle[q].erase(zle[q].begin());
    kolejka[q ^ 1].insert(s);
    debug() << " ["
            << "puste[0]"
               ": "
            << (puste[0])
            << "] "
               " ["
            << "puste[1]"
               ": "
            << (puste[1])
            << "] "
               " ["
            << "zle[0]"
               ": "
            << (zle[0])
            << "] "
               " ["
            << "zle[1]"
               ": "
            << (zle[1])
            << "] "
               " ["
            << "kolejka[0]"
               ": "
            << (kolejka[0])
            << "] "
               " ["
            << "kolejka[1]"
               ": "
            << (kolejka[1]) << "] ";
  }
  int q = 0;
  while (!puste[0].empty() || !puste[1].empty()) {
    if (puste[q].empty()) q ^= 1;
    debug() << " ["
            << "q"
               ": "
            << (q)
            << "] "
               " ["
            << "puste[0]"
               ": "
            << (puste[0])
            << "] "
               " ["
            << "puste[1]"
               ": "
            << (puste[1])
            << "] "
               " ["
            << "zle[0]"
               ": "
            << (zle[0])
            << "] "
               " ["
            << "zle[1]"
               ": "
            << (zle[1])
            << "] "
               " ["
            << "kolejka[0]"
               ": "
            << (kolejka[0])
            << "] "
               " ["
            << "kolejka[1]"
               ": "
            << (kolejka[1]) << "] ";
    if (zle[q ^ 1].empty()) {
      if (!kolejka[q].empty()) {
        result.emplace_back(*kolejka[q].begin(), *puste[q].begin());
        kolejka[q].erase(kolejka[q].begin());
        puste[q].erase(puste[q].begin());
      }
      q ^= 1;
    } else {
      result.emplace_back(*zle[q ^ 1].begin(), *puste[q].begin());
      puste[q ^ 1].insert(*zle[q ^ 1].begin());
      zle[q ^ 1].erase(zle[q ^ 1].begin());
      puste[q].erase(puste[q].begin());
      q ^= 1;
    }
  }
  printf("%d\n", (int)result.size());
  for (const auto& it : result) {
    printf("move %s %s\n", it.first.c_str(), it.second.c_str());
  }
  return 0;
}
