#include <bits/stdc++.h>
int r;
void SetSeed(int r0) { r = r0; }
int GetRandom(int a, int b, int m) {
  r = (a * r + b) % m;
  return r;
}
void PrintSec(std::vector<int>& s) {
  for (size_t i = 0; i < s.size(); ++i) {
    std::cout << s[i];
    if (i != s.size() - 1) {
      std::cout << " ";
    }
  }
}
int main() {
  int a, b, m, r0;
  std::cin >> a >> b >> m >> r0;
  std::vector<int> sequence;
  std::set<int> seqSet;
  SetSeed(r0);
  const int maxLen = 1000000;
  size_t period = 0;
  for (int i = 0; i < maxLen; i++) {
    int x = GetRandom(a, b, m);
    if (seqSet.count(x)) {
      for (size_t j = 0; j < sequence.size(); ++j) {
        if (sequence[j] == x) {
          period = sequence.size() - j;
          break;
        }
      }
      break;
    }
    sequence.push_back(x);
    seqSet.insert(x);
  }
  std::cout << period;
  return 0;
}
