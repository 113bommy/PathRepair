#include <bits/stdc++.h>
using namespace std;
const int INF = std::numeric_limits<int>::max();
struct Cmp {
  Cmp(const vector<deque<int>>& cont) : cont_(&cont) {}
  bool operator()(int i, int j) const {
    do {
      if (!(!cont_->at(i).empty())) {
        std::cerr << "empty deque" << std::endl;
        assert(false);
      }
    } while (false);
    do {
      if (!(!cont_->at(j).empty())) {
        std::cerr << "empty deque" << std::endl;
        assert(false);
      }
    } while (false);
    return cont_->at(i).front() < cont_->at(j).front() ||
           (cont_->at(i).front() == cont_->at(j).front() && i > j);
  }
  const vector<deque<int>>* cont_;
};
void solve() {
  int n;
  cin >> n;
  vector<deque<int>> a(n);
  int numTasks = 0;
  for (int i = 0; i < int(n); ++i) {
    int k;
    cin >> k;
    numTasks += k;
    {
      int x;
      cin >> x;
      a[i].push_back(x);
    }
    long long x, y, m;
    cin >> x >> y >> m;
    for (int j = 0; j < int(k - 1); ++j) {
      a[i].push_back((a[i].back() * x + y) % m);
    }
  }
  a.push_back(deque<int>());
  a.back().push_back(-1);
  Cmp cmp(a);
  std::set<int, Cmp> q(cmp);
  for (int i = 0; i < int(n); ++i) q.insert(i);
  int numDecs = 0;
  bool print = numTasks <= 200 * 1000;
  vector<pair<int, int>> output;
  while (!q.empty()) {
    auto it = q.lower_bound(n);
    if (it == q.end()) {
      it = q.begin();
    }
    q.erase(it);
    int i = *it;
    do {
      if (!(!a[i].empty())) {
        std::cerr << "empty deque" << std::endl;
        assert(false);
      }
    } while (false);
    if (a[i].front() < a.back().back()) {
      ++numDecs;
    }
    a.back().back() = a[i].front();
    if (print) {
      output.push_back(make_pair(a[i].front(), i + 1));
    }
    a[i].pop_front();
    if (!a[i].empty()) {
      q.insert(i);
    }
  }
  cout << numDecs << endl;
  for (int i = 0; i < int(output.size()); ++i) {
    cout << output[i].first << " " << output[i].second << endl;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
