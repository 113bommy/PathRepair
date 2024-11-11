#include <bits/stdc++.h>
using namespace std;
constexpr char nl = '\n';
template <class array, class B>
array&& mini(array&& a, B&& b) {
  if (b < a) a = b;
  return a;
}
template <class array, class B>
array&& maxi(array&& a, B&& b) {
  if (b > a) a = b;
  return a;
}
int first_bit(int x) { return x == 0 ? 0 : sizeof(x) * 8 - __builtin_clz(x); }
int ceil2(int x) { return x < 2 ? x : 1 << first_bit(x - 1); }
constexpr int inf = 0x3f3f3f3f;
constexpr long long inf_l = 0x3f3f3f3f3f3f3f3f;
struct Debug;
template <class T>
auto _is_debug_func(T&& x)
    -> decltype(x(declval<add_lvalue_reference<Debug>::type>()), true_type{});
false_type _is_debug_func(...);
template <class T>
struct is_debug_func : decltype(_is_debug_func(declval<T>())) {};
;
template <class T>
auto _is_func(T&& x) -> decltype(x(), true_type{});
false_type _is_func(...);
template <class T>
struct is_func : decltype(_is_func(declval<T>())) {};
template <class T>
auto _is_string(T&& x) -> decltype(string(x), true_type{});
false_type _is_string(...);
template <class T>
struct is_string : decltype(_is_string(declval<T>())) {};
template <class T>
auto _is_ptr(T&& x)
    -> decltype(*x, typename enable_if<is_string<T>() == false, int>::type(),
                true_type{});
false_type _is_ptr(...);
template <class T>
struct is_ptr : decltype(_is_ptr(declval<T>())) {};
;
template <class T>
auto _is_container(T&& x)
    -> decltype(x.begin(),
                typename enable_if<is_string<T>() == false, int>::type(),
                true_type{});
false_type _is_container(...);
template <class T>
struct is_container : decltype(_is_container(declval<T>())) {};
template <class Iter>
struct Off {
  Iter _a, _b;
};
template <class T>
auto O(T&& x)
    -> decltype(typename enable_if<is_container<T>() == true, int>::type(),
                Off<decltype(x.begin())>()) {
  return {x.begin(), x.end()};
}
template <class T>
auto O(T&& x)
    -> decltype(typename enable_if<is_container<T>() == false, int>::type(),
                x) {
  return x;
}
struct Debug {
  Debug() { cerr << boolalpha; }
  ~Debug() { cerr << nl; }
  Debug& operator()(int x = 1) {
    for (auto _ = (0), ___ = ((x)-1); _ <= ___; ++_) *this << "  ";
    return *this;
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(cerr << x,
                  typename enable_if<
                      is_func<T>() == false && is_ptr<T>() == false &&
                          is_integral<typename remove_reference<T>::type>() ==
                              true,
                      int>::type(),
                  *this) {
    using L = long long;
    if (abs(int(x)) == inf || abs(L(x)) == inf_l)
      cerr << ((int(x) == inf || L(x) == inf_l)     ? "+∞"
               : (int(x) == -inf || L(x) == -inf_l) ? "-∞"
                                                    : "?");
    else
      cerr << x;
    return *this;
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(cerr << x,
                  typename enable_if<
                      is_func<T>() == false && is_ptr<T>() == false &&
                          is_integral<typename remove_reference<T>::type>() ==
                              false,
                      int>::type(),
                  *this) {
    cerr << x;
    return *this;
  }
  template <class T>
  auto operator<<(T&& x) -> decltype(x.first, *this) {
    return *this << "(" << O(x.first) << ", " << O(x.second) << ")";
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(typename enable_if<is_container<T>() == true, int>::type(),
                  *this) {
    *this << "{\n";
    for (auto a = x.begin(); a != x.end(); ++a)
      *this << "  " << distance(x.begin(), a) << ": " << O(*a) << '\n';
    return *this << "}";
  }
  template <class T>
  auto operator<<(T&& x) -> decltype(x._a, *this) {
    *this << "{";
    for (auto a = x._a, b = x._b; a != b; ++a)
      *this << O(*a) << (next(a) == b ? "" : ", ");
    return *this << "}";
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(typename enable_if<is_func<T>() == true, int>::type(),
                  *this) {
    x();
    return *this;
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(typename enable_if<is_debug_func<T>() == true, int>::type(),
                  *this) {
    x(*this);
    return *this;
  }
  template <class T>
  auto operator<<(T&& x)
      -> decltype(typename enable_if<is_ptr<T>() == true &&
                                         is_func<T>() == false &&
                                         is_debug_func<T>() == false,
                                     int>::type(),
                  *this) {
    return *this << *x;
  }
};
struct DebugOff {
  template <class T>
  DebugOff& operator<<(T&&) {
    return *this;
  }
  DebugOff& operator()(int = 0) { return *this; }
};
using VI = vector<int>;
using VVI = vector<VI>;
using L = long long;
using VL = vector<L>;
using VB = vector<bool>;
using II = pair<int, int>;
using VII = vector<II>;
using VVII = vector<VII>;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  int x = 1, lg = 0;
  while (x <= n) {
    ++lg;
    x *= 2;
  }
  cout << lg << nl;
}
