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
namespace tree {
class BinaryIndexedTree {
 public:
  int n;
  std::vector<int> data;
  BinaryIndexedTree() {}
  BinaryIndexedTree(int n) : n(n) { data = std::vector<int>(n + 1000, 0); }
  int sum(int i) {
    i += 5;
    int s = 0;
    while (i > 0) {
      s += data[i];
      i -= i & -i;
    }
    return s;
  }
  void add(int i, int x) {
    i += 5;
    while (i <= n) {
      data[i] += x;
      i += i & -i;
    }
  }
};
}  // namespace tree
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
const int SIZE = 3 * 100000 + 111;
const int NONE = -1;
int n;
int A[SIZE];
int q;
int P[SIZE];
int X[SIZE];
int Y[SIZE];
int B[SIZE];
tree::BinaryIndexedTree bit;
int results[SIZE];
}  // namespace solution
namespace solution {
class Solver {
 public:
  void solve() {
    for (int i = 0; i < SIZE; ++i) set_value(i, 0);
    B[0] = std::numeric_limits<int>::min();
    for (int i = 1; i <= 50; ++i) B[n + i] = std::numeric_limits<int>::max();
    for (int i = 1; i <= n; ++i) B[A[i]] = i;
    for (int i = 1; i <= n; ++i)
      if (B[i] > B[i + 1]) set_value(i, 1);
    for (int i = 0; i < q; ++i) results[i] = query(P[i], X[i], Y[i]);
  }
  int get_value(int x) { return bit.sum(x) - bit.sum(x - 1); }
  void set_value(int x, int new_value) {
    int value = get_value(x);
    bit.add(x, -value);
    bit.add(x, new_value);
  }
  int query(int p, int x, int y) {
    if (p == 1) {
      return query_a(x, y);
    } else if (p == 2) {
      return query_b(x, y);
    }
    return NONE;
  }
  int query_a(int x, int y) { return bit.sum(y - 1) - bit.sum(x - 1) + 1; }
  int query_b(int x, int y) {
    int value_x = A[x];
    int value_y = A[y];
    B[value_x] = y;
    B[value_y] = x;
    swap(A[x], A[y]);
    for (int i = -1; i <= 1; ++i) {
      int n_value_x = value_x + i;
      int n_value_y = value_y + i;
      if (n_value_x > 0 && n_value_x + 1 <= n) {
        set_value(n_value_x, B[n_value_x] > B[n_value_x + 1] ? 1 : 0);
      }
      if (n_value_y > 0 && n_value_y + 1 <= n) {
        set_value(n_value_y, B[n_value_y] > B[n_value_y + 1] ? 1 : 0);
      }
    }
    return NONE;
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
  void init() { bit = tree::BinaryIndexedTree(SIZE); }
  bool input() {
    if (!(cin >> n)) return false;
    for (int i = 1; i <= n; ++i) cin >> A[i];
    cin >> q;
    for (int i = 0; i < q; ++i) cin >> P[i] >> X[i] >> Y[i];
    return true;
  }
  void output() {
    for (int i = 0; i < q; ++i)
      if (results[i] != NONE) cout << results[i] << endl;
  }

 private:
  Solver solver;
};
}  // namespace solution
int main() { return solution::Solution().run(); }
