#include <bits/stdc++.h>
namespace solution {
class SolutionInterface {
 public:
  virtual int run() = 0;

 protected:
  virtual void pre_calc() {}
  virtual bool action() = 0;
  virtual void init(){};
  virtual bool input() { return false; };
  virtual void output(){};
  SolutionInterface() {}

 private:
};
}  // namespace solution
namespace solution {
class SolutionBase : public SolutionInterface {
 public:
  virtual int run() {
    pre_calc();
    while (action())
      ;
    return 0;
  }
};
}  // namespace solution
namespace solution {}
namespace solution {
using namespace std;
}
namespace solution {
const int SIZE = 30;
const long long NONE = std::numeric_limits<long long>::min();
int n, u, r;
long long A[SIZE];
int B[SIZE];
int K[SIZE];
int P[SIZE];
long long result;
}  // namespace solution
namespace solution {
class Solver {
 public:
  void solve() {
    normalize();
    result = NONE;
    rec(0, true, A);
  }
  void normalize() {
    for (int i = 0; i < n; ++i) {
      P[i]--;
    }
  }
  void update_max_score(long long* cur) {
    long long score = 0;
    for (int i = 0; i < n; ++i) {
      score += cur[i] * K[i];
    }
    result = std::max(result, score);
  }
  void rec(int x, bool prev, long long* cur) {
    if (!(x & 1)) {
      update_max_score(cur);
    }
    if (x == u) {
      return;
    }
    long long next[SIZE];
    if (prev) {
      for (int i = 0; i < n; ++i) {
        next[i] = cur[i] ^ B[i];
      }
      rec(x + 1, false, next);
    }
    for (int i = 0; i < n; ++i) {
      next[i] = cur[P[i]] + r;
    }
    rec(x + 1, true, next);
  }

 private:
};
}  // namespace solution
namespace solution {
class Solution : public SolutionBase {
 public:
 protected:
  virtual bool action() {
    init();
    if (!input()) return false;
    solver.solve();
    output();
    return true;
  }
  bool input() {
    if (!(cin >> n >> u >> r)) return false;
    for (int i = 0; i < n; ++i) {
      cin >> A[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> B[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> K[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> P[i];
    }
    return true;
  }
  void output() { cout << result << endl; }

 private:
  Solver solver;
};
}  // namespace solution
int main() { return solution::Solution().run(); }
