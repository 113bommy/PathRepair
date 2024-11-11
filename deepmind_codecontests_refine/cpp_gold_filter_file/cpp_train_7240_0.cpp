#include <bits/stdc++.h>
#pragma GCC target("sse4,avx")
void run(std::istream &in, std::ostream &out) {
  int n;
  in >> n;
  std::vector<int> as(n);
  for (int i = 0; i < n; i++) {
    in >> as[i];
  }
  std::vector<int> bs(n);
  bs[n - 1] = as[n - 1];
  for (int i = n - 2; i >= 0; i--) {
    bs[i] = as[i] + as[i + 1];
  }
  for (int i = 0; i < n; i++) {
    out << bs[i] << " ";
  }
  out << std::endl;
}
int main() {
  std::cin.sync_with_stdio(false);
  std::cin.tie(nullptr);
  run(std::cin, std::cout);
  return 0;
}
