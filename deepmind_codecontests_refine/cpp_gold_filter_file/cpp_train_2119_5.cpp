#include <bits/stdc++.h>
bool sortPair(const std::pair<int, int>& a1, const std::pair<int, int>& a2) {
  return a1.second < a2.second;
}
int main() {
  int n, d, a, b;
  std::cin >> n >> d;
  std::cin >> a >> b;
  std::vector<std::pair<int, int> > clients(n);
  for (int ic = 0; ic < n; ic++) {
    int x, y;
    std::cin >> x >> y;
    clients[ic] = std::make_pair(ic, a * x + b * y);
  }
  std::sort(clients.begin(), clients.end(), sortPair);
  unsigned int sum = 0, ic = 0;
  std::vector<int> maxClients;
  while (ic < clients.size()) {
    sum += clients[ic].second;
    if (sum > d) break;
    maxClients.push_back(clients[ic].first + 1);
    ic++;
  }
  std::cout << maxClients.size() << "\n";
  for (int ix = 0; ix < maxClients.size(); ix++) {
    std::cout << maxClients[ix] << " ";
  }
  std::cout << "\n";
  return 0;
}
