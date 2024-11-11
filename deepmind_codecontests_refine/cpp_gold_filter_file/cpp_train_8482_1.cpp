#include <bits/stdc++.h>
class CaseOfFugitive {
  int n, m;
  struct Interval {
    long long l;
    long long r;
    int id;
    bool operator>(Interval oth) const { return r > oth.r; }
  };
  struct Bridge {
    long long len;
    int id;
    bool operator<(Bridge oth) const { return len < oth.len; }
  };
  std::vector<int> solution;
  bool isIntervalCovered(std::vector<Interval> Is, std::vector<Bridge> Pts) {
    std::priority_queue<Interval, std::vector<Interval>, std::greater<Interval>>
        Left;
    std::sort(Is.rbegin(), Is.rend(),
              [](Interval a, Interval b) { return a.l < b.l; });
    std::sort(Pts.begin(), Pts.end());
    for (Bridge b : Pts) {
      long long id = b.id, p = b.len;
      while (Is.size() and Is.back().l <= p) {
        Left.push(Is.back());
        Is.pop_back();
      }
      if (Left.empty()) continue;
      if (Left.top().r <= p) {
        return false;
      }
      solution[Left.top().id] = id;
      Left.pop();
    }
    return Left.empty() and Is.empty();
  }

 public:
  void run(std::istream &in, std::ostream &out) {
    in >> n >> m;
    long long prea, preb;
    in >> prea >> preb;
    std::vector<Interval> Is;
    for (int i = 0; i < n - 1; ++i) {
      long long a, b;
      in >> a >> b;
      Is.push_back({a - preb, b - prea + 1, i});
      prea = a, preb = b;
    }
    std::vector<Bridge> Pts;
    for (int i = 0; i < m; ++i) {
      long long p;
      in >> p;
      Pts.push_back({p, i});
    }
    solution.resize(n - 1);
    if (not isIntervalCovered(Is, Pts)) {
      out << "No\n";
    } else {
      out << "Yes\n";
      for (int i = 0; i < n - 1; ++i) {
        out << solution[i] + 1 << " \n"[i == n - 2];
      }
    }
  }
};
int main() {
  std::ios_base::sync_with_stdio(false);
  CaseOfFugitive().run(std::cin, std::cout);
  return 0;
}
