#include <bits/stdc++.h>
namespace {
template <typename FArgType, typename... T>
void print(FArgType &&arg, T &&...args) {
  std::cout << arg;
  if constexpr (sizeof...(args) > 0) print(std::forward<T>(args)...);
}
template <typename... T>
void println(T &&...args) {
  print(std::forward<T>(args)..., '\n');
}
template <typename T>
T input() {
  T val;
  std::cin >> val;
  return val;
}
template <typename T>
void input(std::vector<T> &vector, uint32_t num) {
  vector.clear();
  vector.reserve(num);
  while (num--) {
    vector.emplace_back(input<T>());
  }
}
template <typename T, size_t size>
void input(std::array<T, size> &array) {
  T val;
  for (uint32_t i = 0; i != size; ++i) {
    array[i] = input<T>();
  }
}
}  // namespace
int main() {
  uint32_t n, m, x, y;
  std::cin >> n >> m >> x >> y;
  uint32_t mx = x, my = y;
  while (mx) {
    println(mx, " ", my);
    --mx;
  }
  mx = x + 1;
  while (mx <= n) {
    println(mx, " ", my);
    ++mx;
  }
  mx = n;
  my = 1;
  for (; my <= m; ++my) {
    if (my == y) continue;
    if (mx == n) {
      for (; mx >= 1; --mx) {
        println(mx, " ", my);
      }
      mx = 1;
    } else if (mx == 1) {
      for (; mx <= n; ++mx) {
        println(mx, " ", my);
      }
      mx = n;
    }
  }
}
