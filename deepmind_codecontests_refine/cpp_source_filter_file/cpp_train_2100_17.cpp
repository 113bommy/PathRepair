#include <bits/stdc++.h>
int main() {
  int s, b;
  std::cin >> s >> b;
  std::vector<int> ships(s);
  for (int i = 0; i < s; i++) scanf("%d", &ships[i]);
  std::vector<std::pair<int, int>> bases(b);
  bases.push_back({0, 0});
  for (int i = 0; i < b; i++) scanf("%d%d", &bases[i].first, &bases[i].second);
  std::sort(bases.begin(), bases.end());
  for (int i = 1; i < b; i++) bases[i].second += bases[i - 1].second;
  for (int i = 0; i < s; i++) {
    int force = ships[i];
    auto p = std::upper_bound(bases.begin(), bases.end(),
                              std::make_pair(force, INT_MAX));
    p--;
    printf("%d ", p->second);
  }
}
