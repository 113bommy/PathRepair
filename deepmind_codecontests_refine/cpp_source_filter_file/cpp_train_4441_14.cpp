#include <bits/stdc++.h>
int main(void) {
  long long n;
  std::scanf("%lld", &n);
  std::vector<std::vector<long long>> graph(n);
  for (long long i = 1, tmp; i < n; ++i) {
    std::scanf("%lld", &tmp);
    graph[tmp - 1].push_back(i);
  }
  std::queue<long long> order;
  order.push(0);
  std::vector<long long> height_pop(n), heights(n);
  height_pop[0] = 1;
  heights[0] = 1;
  while (!order.empty()) {
    long long best = order.front();
    order.pop();
    for (const auto& neigh : graph[best]) {
      heights[neigh] = heights[best] + 1;
      height_pop[heights[neigh]]++;
      order.push(neigh);
    }
  }
  long long tot = 0;
  for (const auto& hc : height_pop) tot += hc & 1;
  std::printf("%lld\n", tot);
  return 0;
}
