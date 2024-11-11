#include <bits/stdc++.h>
using namespace std;
template <typename T>
T read() {
  T res;
  std::cin >> res;
  return res;
}
template <typename T>
void print(const T& t) {
  std::cout << t;
}
template <>
int read<int>() {
  int res;
  scanf("%d", &res);
  return res;
}
template <>
void print<int>(const int& t) {
  printf("%d", t);
};
template <>
unsigned int read<unsigned int>() {
  unsigned int res;
  scanf("%u", &res);
  return res;
}
template <>
void print<unsigned int>(const unsigned int& t) {
  printf("%u", t);
};
template <>
int64_t read<int64_t>() {
  int64_t res;
  scanf("%lld", &res);
  return res;
}
template <>
void print<int64_t>(const int64_t& t) {
  printf("%lld", t);
};
template <>
float read<float>() {
  float res;
  scanf("%f", &res);
  return res;
}
template <>
void print<float>(const float& t) {
  printf("%f", t);
};
template <>
double read<double>() {
  double res;
  scanf("%lf", &res);
  return res;
}
template <>
void print<double>(const double& t) {
  printf("%lf", t);
};
template <>
char read<char>() {
  char res;
  scanf("%c", &res);
  return res;
}
template <>
void print<char>(const char& t) {
  printf("%c", t);
};
namespace internal {
template <typename ValueT>
class IterableRange {
 public:
  class iterator {
   public:
    iterator(ValueT v__) : v_(v__) {}
    iterator& operator++() {
      ++v_;
      return *this;
    }
    bool operator==(iterator rhs) const { return v_ == rhs.v_; }
    bool operator!=(iterator rhs) const { return v_ != rhs.v_; }
    ValueT operator*() const { return v_; }
    ValueT operator->() const { return v_; }

   private:
    ValueT v_ = {};
  };
  IterableRange(ValueT begin__, ValueT end__)
      : begin_value_(std::min(begin__, end__)), end_value_(end__) {}
  iterator begin() const { return {begin_value_}; }
  iterator end() const { return {end_value_}; }

 private:
  ValueT begin_value_ = {};
  ValueT end_value_ = {};
};
}  // namespace internal
template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT end) {
  return {{}, end};
}
template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT begin, ValueT end) {
  return {begin, end};
}
using namespace std;
class Solver645B {
 public:
  void run();
};
void Solver645B::run() {
  int64_t a, b;
  cin >> a >> b;
  int64_t l = 0;
  int64_t r = a - 1;
  int64_t ans = 0;
  while (r > l && b > 0) {
    ans += 2 * (r - l) - 1;
    ++l;
    --r;
    --b;
  }
  cout << ans;
}
int main() {
  Solver645B solver;
  solver.run();
}
