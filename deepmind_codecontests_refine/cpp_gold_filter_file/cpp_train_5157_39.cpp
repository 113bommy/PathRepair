#include <bits/stdc++.h>
int orientation(std::pair<int, int> p, std::pair<int, int> q,
                std::pair<int, int> r) {
  int val = (q.second - p.second) * (r.first - q.first) -
            (q.first - p.first) * (r.second - q.second);
  if (val == 0) return 0;
  return (val > 0) ? 1 : 2;
}
int main(int argc, char **argv) {
  int n;
  scanf("%d", &n);
  std::vector<std::pair<int, int>> arr(n + 1);
  for (int i = 0; i <= n; i++) {
    scanf("%d %d", &arr[i].first, &arr[i].second);
  }
  int count = 0;
  for (int i = 2; i <= n; i++) {
    if (orientation(arr[i - 2], arr[i - 1], arr[i]) == 2) {
      count++;
    }
  }
  printf("%d\n", count);
}
