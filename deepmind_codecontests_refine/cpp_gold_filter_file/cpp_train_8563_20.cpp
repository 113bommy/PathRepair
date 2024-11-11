#include <bits/stdc++.h>
void reduce(unsigned& nom, unsigned& denom) {
  bool reduced = true;
  while (reduced) {
    reduced = false;
    for (unsigned i = 2; !reduced && i < 1000; ++i) {
      if (nom % i == 0 && denom % i == 0) {
        nom /= i;
        denom /= i;
        reduced = true;
      }
    }
  }
}
void solve() {
  unsigned sum = 0;
  unsigned A;
  std::cin >> A;
  for (unsigned i = 2; i < A; ++i) {
    auto val = A;
    while (val > 0) {
      sum += val % i;
      val /= i;
    }
  }
  auto nom = sum;
  auto denom = A - 2;
  reduce(nom, denom);
  std::cout << nom << "/" << denom << std::endl;
}
int main(int argc, char* argv[]) {
  { solve(); }
  return 0;
}
