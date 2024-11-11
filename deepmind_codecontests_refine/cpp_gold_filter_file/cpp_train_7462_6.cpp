#include <bits/stdc++.h>
using namespace std;
using li = long long;
using ld = long double;
void solve(bool read);
int main() {
  auto t0 = clock();
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.precision(20);
  cout << fixed;
  solve(true);
}
bool isp(string s) {
  string x = s;
  reverse((x).begin(), (x).end());
  return x == s;
}
vector<int> deg;
vector<vector<int>> e;
vector<vector<int>> paths;
void dfs(int v, int p) {
  bool one = true;
  for (int u : e[v]) {
    if (u == p) continue;
    if (p != -1 && !one) {
      cout << "No\n";
      exit(0);
    }
    if (p == -1) {
      paths.emplace_back();
    }
    paths.back().push_back(u);
    dfs(u, v);
    one = false;
  }
}
bool isPrime(int x) {
  for (int y = 2; y * y <= x; ++y)
    if (x % y == 0) return false;
  return true;
}
struct Cs {
  int l, r;
  bool operator<(const Cs& rhs) const { return l < rhs.l; }
};
struct Cset {
  vector<Cs> cs;
  void add(int l, int r) {
    for (Cs& s : cs) {
      if (s.l <= l - 1 && s.r >= l - 1) {
        s.r = max(s.r, r);
        return;
      }
      if (s.l <= r + 1 && s.r >= r + 1) {
        s.l = min(s.l, l);
        return;
      }
    }
    auto s = Cs{l, r};
    cs.insert(lower_bound((cs).begin(), (cs).end(), s), s);
  }
  Cset intersect(Cset& other) {
    static Cset res;
    res.cs.clear();
    int j = 0;
    for (auto s1 : cs) {
      while (j < other.cs.size() && other.cs[j].r < s1.l) {
        ++j;
      }
      for (int t = j; t < other.cs.size(); ++t) {
        if (other.cs[t].l > s1.r) {
          break;
        }
        auto& s2 = other.cs[t];
        Cs inter = {max(s1.l, s2.l), min(s1.r, s2.r)};
        if (inter.r >= inter.l) res.add(inter.l, inter.r);
      }
    }
    return res;
  }
  void addCirc(int l, int r, int n) {
    while (l < 0) {
      l += n;
      r += n;
    }
    if (r >= n) {
      add(l, n - 1);
      add(0, r - n);
    } else {
      add(l, r);
    }
  }
  bool isCircular(int n) {
    sort((cs).begin(), (cs).end());
    return cs.size() == 1 ||
           (cs.size() == 2 && cs[0].l == 0 && cs[1].r == n - 1);
  }
};
void solve(bool __attribute__((unused)) read) {
  read = true;
  int n, L;
  cin >> n >> L;
  if (!read) {
    n = 2e5;
    L = 1e9;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    if (read)
      cin >> a[i];
    else
      a[i] = rand() % L;
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    if (read)
      cin >> b[i];
    else
      b[i] = rand() % L;
  }
  sort((a).begin(), (a).end());
  sort((b).begin(), (b).end());
  vector<int> order(n);
  iota((order).begin(), (order).end(), 0);
  int mx = 0;
  Cset res;
  Cset ok;
  auto can = [&](li d) {
    ok.cs.clear();
    res.cs.clear();
    res.add(0, n - 1);
    for (int i = 0; i < n; ++i) {
      ok.cs.clear();
      auto now = a[order[i]];
      auto from = b.begin();
      for (int t = 0; t < 3; ++t) {
        int correct = (t - 1) * L;
        auto it1 = lower_bound(from, b.end(), now - d + correct) - b.begin();
        li until = now + d + correct;
        if (until > 2e9) until = 2e9;
        auto it2 = upper_bound(from, b.end(), (int)until) - b.begin();
        from = b.begin() + it2;
        if (it2 != it1) {
          --it2;
          ok.addCirc(it1 - order[i], it2 - order[i], n);
        }
      }
      res = res.intersect(ok);
      if (res.cs.empty()) {
        swap(order[0], order[i]);
        return false;
      }
    }
    return true;
  };
  int low = -1, high = L / 2;
  while (low + 1 != high) {
    int m = (low + high) / 2;
    if (can(m))
      high = m;
    else
      low = m;
  }
  cout << high << endl;
}
