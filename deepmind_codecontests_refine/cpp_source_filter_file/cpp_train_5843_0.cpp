#include <bits/stdc++.h>
using namespace std;
long long magic_const = 3e18;
class solver_1 {
 public:
  long long solve(int n, int k, int x, vector<long long> &v) {
    vector<multiset<long long>> sets(x + 1);
    vector<vector<long long>> answer(n + 1, vector<long long>(x + 1, -1));
    answer[0][0] = 0;
    sets[0].insert(0);
    for (int i = 1; i < n + 1; i++) {
      for (int x1 = 1; x1 <= min(x, i); x1++) {
        if (sets[x1 - 1].size() > 0)
          answer[i][x1] = (*(sets[x1 - 1].rbegin())) + v[i - 1];
      }
      for (int x1 = 0; x1 <= x; x1++) {
        if (answer[i][x1] != -1) sets[x1].insert(answer[i][x1]);
        auto previndex = i - k;
        if (previndex >= 0)
          if (answer[previndex][x1] != -1)
            sets[x1].erase(sets[x1].lower_bound(answer[previndex][x1]));
      }
    }
    sets[x].insert(-1);
    return *sets[x].rbegin();
  }
};
class solver_2 {
 public:
  vector<priority_queue<pair<long long, int>>> sets;
  void clear_queue(int n) {
    for (int i = 0; i < sets.size(); i++)
      while (sets[i].size() > 0 && sets[i].top().second < n) sets[i].pop();
  }
  long long solve(int n, int k, int x, vector<long long> &v) {
    sets.resize(x + 1);
    vector<vector<long long>> answer(n + 1, vector<long long>(x + 1, -1));
    answer[0][0] = 0;
    sets[0].push({0, 0});
    for (int i = 1; i < n + 1; i++) {
      clear_queue(i - k);
      for (int x1 = 1; x1 <= min(x, i); x1++) {
        if (sets[x1 - 1].size() > 0)
          answer[i][x1] = sets[x1 - 1].top().first + v[i - 1];
      }
      for (int x1 = 0; x1 <= x; x1++) {
        if (answer[i][x1] != -1) sets[x1].push({answer[i][x1], i});
      }
    }
    sets[x].push({-1, 100000});
    clear_queue(n + 1 - k);
    return sets[x].top().first;
  }
};
class MAXQ {
 private:
  int indexer = 0;
  stack<pair<long long, int>> inner;
  stack<pair<long long, int>> outer;
  long long maxin = -1;
  void from_inner_to_outer() {
    while (outer.size() > 0) outer.pop();
    long long maxnow = -1;
    while (inner.size() > 0) {
      outer.push({max(inner.top().first, maxnow), inner.top().second});
      maxnow = inner.top().first;
      inner.pop();
    }
    maxin = -1;
  }

 public:
  long long get_max() {
    if (outer.size() == 0) return maxin;
    return max(outer.top().first, maxin);
  }
  void push(long long first, int second) {
    inner.push({first, second});
    maxin = max(maxin, first);
  }
  void clear(int n) {
    while (outer.size() > 0 && outer.top().second < n) outer.pop();
    if (outer.size() == 0) from_inner_to_outer();
    while (outer.size() > 0 && outer.top().second < n) outer.pop();
  }
};
class solver_3 {
 public:
  vector<MAXQ> sets;
  void clear_queue(int n) {
    for (int i = 0; i < sets.size(); i++) sets[i].clear(n);
  }
  long long solve(int n, int k, int x, vector<long long> &v) {
    sets.resize(x + 1);
    sets[0].push(0, 0);
    for (int i = 1; i < n + 1; i++) {
      clear_queue(i - k);
      for (int x1 = x; x1 > 0; x1--) {
        if (sets[x1 - 1].get_max() != -1)
          sets[x1].push(sets[x1 - 1].get_max() + v[i - 1], i);
      }
    }
    clear_queue(n + 1 - k);
    return sets[x].get_max();
  }
};
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  srand(555);
  int n, k, x;
  cin >> n >> k >> x;
  vector<long long> v(n);
  for (auto &i : v) cin >> i;
  cout << solver_3().solve(n, k, x, v) << endl;
}
