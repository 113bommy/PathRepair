#include <bits/stdc++.h>
using namespace std;
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(bool b) { return (b ? "true" : "false"); }
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for (const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
void debug_out() { cerr << '\n'; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
int transfer_worst(set<pair<int, int> > &from, set<pair<int, int> > &to) {
  assert(!from.empty());
  int added_val = (*from.rbegin()).first;
  to.insert(*from.rbegin());
  from.erase(*from.rbegin());
  return added_val;
}
int transfer_best(set<pair<int, int> > &from, set<pair<int, int> > &to) {
  assert(!from.empty());
  int added_val = (*from.begin()).first;
  to.insert(*from.begin());
  from.erase(*from.begin());
  return added_val;
}
int solve(vector<pair<int, int> > b00, vector<pair<int, int> > b01,
          vector<pair<int, int> > b10, vector<pair<int, int> > b11, int M,
          int K, bool print = false, int ans = -1) {
  if (print && ans == -1) {
    cout << -1 << '\n';
    return 0;
  }
  set<pair<int, int> > ans_set, free_set;
  for (auto u : b00) {
    free_set.insert(u);
  }
  for (auto u : b10) {
    free_set.insert(u);
  }
  for (auto u : b01) {
    free_set.insert(u);
  }
  int P01 = 0, P10 = 0;
  int sum_sofar = 0;
  for (auto u : b11) sum_sofar += u.first;
  int best = 2e9 + 5;
  int X = b11.size();
  42;
  42;
  42;
  42;
  for (int i = (int)b11.size() - 1; i >= -1; i--) {
    if (i + 1 < b11.size()) {
      sum_sofar -= b11[i + 1].first;
      X--;
    }
    int req01 = max(K - X, 0), req10 = max(K - X, 0);
    int req_loose = M - X - req01 - req10;
    if (req_loose < 0 || req01 > b01.size() || req10 > b10.size() ||
        req10 + req01 + req_loose > b01.size() + b10.size() + b00.size())
      continue;
    while (P01 < req01) {
      auto el = b01[P01];
      if (ans_set.find(el) == ans_set.end()) {
        sum_sofar += el.first;
      }
      ans_set.erase(el);
      free_set.erase(el);
      P01++;
    }
    while (P10 < req10) {
      auto el = b10[P10];
      if (ans_set.find(el) == ans_set.end()) {
        sum_sofar += el.first;
      }
      ans_set.erase(el);
      free_set.erase(el);
      P10++;
    }
    while (ans_set.size() < req_loose) {
      sum_sofar += transfer_best(free_set, ans_set);
    }
    while (ans_set.size() > req_loose) {
      sum_sofar -= transfer_best(ans_set, free_set);
    }
    best = min(best, sum_sofar);
    if (sum_sofar == ans) {
      cout << ans << '\n';
      int ga = 0;
      for (auto u : ans_set) {
        cout << u.second + 1 << ' ';
        ga += u.first;
      }
      for (int i = 0; i < P01; i++) {
        cout << b01[i].second + 1 << ' ';
        ga += b01[i].first;
      }
      for (int i = 0; i < P10; i++) {
        cout << b10[i].second + 1 << ' ';
        ga += b10[i].first;
      }
      for (int i = 0; i < X; i++) {
        cout << b11[i].second + 1 << ' ';
        ga += b11[i].first;
      }
      assert(ga == ans);
      return 0;
    }
  }
  assert(!print);
  return best > 2e9 ? -1 : best;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, M, K;
  cin >> n >> M >> K;
  vector<pair<int, int> > b00, b01, b10, b11;
  for (int i = 0; i < n; i++) {
    int first, a, b;
    cin >> first >> a >> b;
    if (a && b) b11.push_back({first, i});
    if (a && !b) b10.push_back({first, i});
    if (!a && b) b01.push_back({first, i});
    if (!a && !b) b00.push_back({first, i});
  }
  sort((b11).begin(), (b11).end());
  sort((b00).begin(), (b00).end());
  sort((b10).begin(), (b10).end());
  sort((b01).begin(), (b01).end());
  int ans = solve(b00, b01, b10, b11, M, K);
  solve(b00, b01, b10, b11, M, K, 1, ans);
  return 0;
}
