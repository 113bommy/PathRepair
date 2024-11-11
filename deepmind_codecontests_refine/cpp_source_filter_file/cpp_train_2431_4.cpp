#include <bits/stdc++.h>
namespace utils {
template <class T, class V>
void fill(T& v, const int& n, const V& value);
template <class T>
void copy(const T& s, T& t);
template <class T>
void copy(const T& s, const int& n, T& t);
template <class T>
void sort(T& v);
template <class T>
void sort(T& v, const int& n);
}  // namespace utils
namespace utils {
template <class T>
void max(T& a, const T& b);
template <class T>
void min(T& a, const T& b);
template <class T>
std::string to_string(const T& v);
template <class T>
T to_type(const std::string& s);
}  // namespace utils
namespace solution {
struct Input;
struct Output;
struct Storages {
  Input* in;
  Output* out;
};
}  // namespace solution
namespace solution {
struct SolverInterface {
  virtual ~SolverInterface() {}
  virtual const Output* solve(const Input* in, Output* out) = 0;
};
}  // namespace solution
namespace solution {
struct SolutionInterface {
  virtual ~SolutionInterface(){};
  virtual int run() = 0;
  virtual bool action() = 0;
  virtual bool input(Input* s) = 0;
  virtual void output(const Output* s) = 0;
  virtual void before_all_actions() {}
  virtual void after_all_actions() {}
  virtual void before_action(const int& test_no) {}
  virtual void after_action(const int& test_no) {}
  SolverInterface* solver;
  Storages* storages;
};
}  // namespace solution
namespace solution {
struct SolutionBase : SolutionInterface {
  virtual ~SolutionBase(){};
  int run() {
    this->before_all_actions();
    for (;;) {
      this->before_action(-1);
      if (!this->action()) {
        this->after_action(-1);
        break;
      }
      this->after_action(-1);
    };
    this->after_all_actions();
    return 0;
  }
  bool action() {
    if (!this->input(this->storages->in)) {
      return false;
    }
    this->output(solver->solve(this->storages->in, this->storages->out));
    return true;
  }
};
}  // namespace solution
namespace solution {}
namespace solution {
const long long SIZE = 100000 + 11;
const long long NONE = std::numeric_limits<long long>::min();
}  // namespace solution
namespace solution {
using namespace utils;
}
namespace solution {
struct Input {
  long long N;
  std::array<long long, SIZE> A;
};
struct Output {
  long long result;
};
}  // namespace solution
namespace solution {
struct Counter {
  long long bridges;
  std::array<long long, SIZE> A;
  std::array<long long, SIZE> left;
  std::array<long long, SIZE> right;
  std::array<long long, SIZE> odd;
  std::array<long long, SIZE> even;
  std::array<long long, SIZE> sum_odd;
  void init() { copy(in->A, A); }
  void init_vars() {
    bridges = in->N - 1;
    init_odd_even();
    init_left_right();
    init_sum_odd();
  }
  static long long get_even(const long long& x) {
    if (x % 2 == 0) return x;
    return x - 1;
  }
  static long long get_odd(const long long& x) {
    if (x % 2 == 1) return x;
    return x - 1;
  }
  void init_sum_odd() {
    sum_odd[0] = 0;
    for (auto i = 1; i <= bridges; ++i) {
      sum_odd[i] = sum_odd[i - 1] + (i - 1 < bridges ? odd[i - 1] : 0);
    }
  }
  void init_left_right() {
    left[0] = 0;
    for (auto i = 1; i <= bridges; ++i) {
      if (A[i - 1] == 1) {
        left[i] = 0;
      } else {
        left[i] = left[i - 1] + (i - 1 < bridges ? even[i - 1] : 0);
      }
    }
    right[bridges] = right[bridges - 1] = 0;
    for (auto i = bridges - 1; i >= 0; --i) {
      if (i < bridges && A[i] == 1) {
        right[i] = 0;
      } else {
        right[i] = right[i + 1] + (i < bridges ? even[i] : 0);
      }
    }
  }
  void init_odd_even() {
    for (auto i = 0; i < bridges; ++i) {
      odd[i] = get_odd(A[i]);
      even[i] = get_even(A[i]);
    }
  }
  long long f(const long long& l, const long long& r) {
    return left[l] + right[r] + (sum_odd[r] - sum_odd[l]);
  }
  long long find_max() {
    long long res = 0;
    long long best = 0;
    for (auto i = 0; i < bridges; ++i) {
      max(best, left[i] - sum_odd[i]);
      max(res, best + right[i] + sum_odd[i]);
    }
    return res;
  }
  long long count() {
    if (in->N == 2) return in->A[0];
    long long res = in->N - 1;
    init_vars();
    max(res, find_max());
    std::reverse(std::begin(A), std::begin(A) + bridges);
    init_vars();
    max(res, find_max());
    return res;
  }
  const Input* in;
  Counter(const Input* in) : in(in) { init(); }
  static std::unique_ptr<Counter> create(const Input* in) {
    return std::unique_ptr<Counter>(new Counter(in));
  }
};
struct Solver : SolverInterface {
  const Output* solve(const Input* in, Output* out) {
    auto counter = Counter::create(in);
    out->result = counter->count();
    return out;
  }
};
}  // namespace solution
namespace solution {
struct Solution : SolutionBase {
  bool input(Input* in) {
    if (!(std::cin >> in->N && in->N >= 2)) return false;
    for (auto i = 0; i < in->N - 1; ++i)
      if (!(std::cin >> in->A[i])) return false;
    return true;
  }
  void output(const Output* out) { std::cout << out->result << std::endl; }
};
}  // namespace solution
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  using namespace solution;
  static Input in;
  static Output out;
  static Storages storages;
  static Solution solution;
  static Solver solver;
  storages.in = &in;
  storages.out = &out;
  solution.storages = &storages;
  solution.solver = &solver;
  return solution.run();
}
namespace utils {
template <class T, class V>
void fill(T& v, const int& n, const V& value) {
  std::fill(std::begin(v), std::begin(v) + n, value);
}
template <class T>
void copy(const T& s, T& t) {
  std::copy(std::begin(s), std::end(s), std::begin(t));
}
template <class T>
void copy(const T& s, const int& n, T& t) {
  std::copy(std::begin(s), std::begin(s) + n, std::begin(t));
}
template <class T>
void sort(T& v) {
  std::sort(std::begin(v), std::end(v));
}
template <class T>
void sort(T& v, const int& n) {
  std::sort(std::begin(v), std::begin(v) + n);
}
}  // namespace utils
namespace utils {
template <class T>
void max(T& a, const T& b) {
  a = std::max(a, b);
}
template <class T>
void min(T& a, const T& b) {
  a = std::min(a, b);
}
template <class T>
std::string to_string(const T& v) {
  std::ostringstream oss;
  oss << v;
  return oss.str();
}
template <class T>
T to_type(const std::string& s) {
  std::istringstream iss(s);
  T res;
  iss >> res;
  return res;
}
}  // namespace utils
