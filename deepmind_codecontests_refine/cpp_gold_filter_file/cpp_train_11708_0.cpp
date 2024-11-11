#include <bits/stdc++.h>
int main() {
  int32_t n, m;
  std::cin >> n >> m;
  std::pair<uint64_t, int32_t>* samples = new std::pair<uint64_t, int32_t>[m];
  for (int32_t i = 0; i < m; i++) {
    std::string str;
    int32_t collisions;
    std::cin >> str >> collisions;
    uint64_t num = 0;
    for (int32_t j = 0; j < n; j++) {
      num *= 2;
      num += str[j] - '0';
    }
    samples[i] = {num, collisions};
  }
  int32_t first_half = n / 2;
  int32_t second_half = n - first_half;
  std::map<std::vector<int32_t>, int32_t> first_half_collisions;
  for (uint32_t i = 0; i < (1 << first_half); i++) {
    std::vector<int32_t> collisions;
    collisions.resize(m);
    for (int32_t j = 0; j < m; j++) {
      collisions[j] = __builtin_popcount((samples[j].first >> second_half) ^ i);
    }
    first_half_collisions[collisions]++;
  }
  int64_t answer = 0;
  for (uint32_t i = 0; i < (1 << second_half); i++) {
    std::vector<int32_t> supplemental_collisions;
    supplemental_collisions.resize(m);
    for (int32_t j = 0; j < m; j++) {
      supplemental_collisions[j] =
          samples[j].second -
          __builtin_popcount((samples[j].first & ((1 << second_half) - 1)) ^ i);
    }
    auto it = first_half_collisions.find(supplemental_collisions);
    if (it != first_half_collisions.end()) answer += it->second;
  }
  std::cout << answer;
  return 0;
}
