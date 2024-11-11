#include <bits/stdc++.h>
const int maxLog = 30;
class LinearBasis {
 public:
  void init() { std::memset(val, 0, sizeof(val)); }
  void insert(unsigned int x) {
    for (int i = maxLog; x && i >= 0; --i) {
      if (!(x & (1u << i))) continue;
      if (val[i])
        x ^= val[i];
      else {
        for (int j = 0; j < i; ++j)
          if (x & (1u << j)) x ^= val[j];
        for (int j = maxLog; j > i; --j)
          if (val[j] & (1u << i)) val[j] ^= x;
        val[i] = x;
        break;
      }
    }
  }
  int size() const { return maxLog + 1 - std::count(val, val + maxLog + 1, 0); }

 private:
  unsigned int val[maxLog + 1];
};
int main() {
  std::ios::sync_with_stdio(false);
  int n;
  unsigned int acc = 0;
  LinearBasis lb;
  std::cin >> n;
  lb.init();
  for (int i = 0; i < n; ++i) {
    unsigned int v;
    std::cin >> v;
    acc ^= v;
    lb.insert(v);
  }
  if (!acc)
    std::cout << "-1\n";
  else
    std::cout << lb.size() + 1 << "\n";
  return 0;
}
