#include <bits/stdc++.h>
int n;
inline int shf(int x, int y) { return (x - 1 + y + n) % n + 1; }
std::vector<std::pair<std::pair<int, int>, std::pair<int, int> > > ans;
int main() {
  scanf("%d", &n);
  if (n & 1) {
    for (int i = 2, j = 3; j <= n; i += 2, j += 2)
      for (int o = 0; o < 2; o++)
        ans.push_back(
            std::make_pair(std::make_pair(i, j), std::make_pair(1, 0)));
    for (int i = 2, j = 3; j <= n; i += 2, j += 2)
      for (int k = 2, l = 3; k < i; k += 2, l += 2)
        for (int o = 0; o < 2; o++)
          ans.push_back(
              std::make_pair(std::make_pair(i, k), std::make_pair(j, l)));
  } else {
    for (int i = 1; i <= n; i++)
      ans.push_back(std::make_pair(std::make_pair(i, shf(i, 1)),
                                   std::make_pair(shf(i, 2), 0)));
    for (int k = 3; k <= n / 2; k++)
      for (int i = 1; i <= n / 2; i++)
        ans.push_back(std::make_pair(std::make_pair(i, shf(i, k)),
                                     std::make_pair(shf(i, 1), shf(i, 1 - k))));
  }
  printf("%d\n", ans.size());
  for (auto x : ans)
    if (x.second.second)
      printf("4 %d %d %d %d\n", x.first.first, x.first.second, x.second.first,
             x.second.second);
    else
      printf("3 %d %d %d\n", x.first.first, x.first.second, x.second.first);
}
