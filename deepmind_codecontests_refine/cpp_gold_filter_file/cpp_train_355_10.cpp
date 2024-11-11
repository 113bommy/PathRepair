#include <bits/stdc++.h>
struct Arrete {
  int v, c;
};
struct Point {
  int x, y;
  double distance(Point other) const {
    return sqrt((x - other.x) * (x - other.x) + (y - other.y) * (y - other.y));
  }
};
const int NB_D = 4;
const int DY[] = {-1, 1, 0, 0};
const int DX[] = {0, 0, -1, 1};
int main(void) {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(0);
  std::cout.tie(0);
  int N;
  std::cin >> N;
  std::vector<int> arr(N);
  std::vector<std::pair<int, int> > sorted(N);
  std::vector<int> next(N);
  std::vector<int> prev(N);
  for (int i(0); i < N; ++i) {
    prev[i] = i - 1;
    next[i] = i + 1;
    std::cin >> arr[i];
    sorted[i] = {arr[i], i};
  }
  std::sort((sorted).begin(), (sorted).end());
  long long ans(0);
  int left(0), right(N - 1);
  sorted.pop_back();
  if (!sorted.empty()) sorted.pop_back();
  for (auto &v : sorted) {
    if (v.second == left) {
      ans += v.first;
      left = next[left];
      continue;
    }
    if (v.second == right) {
      ans += v.first;
      right = prev[right];
      continue;
    }
    ans += std::min(arr[prev[v.second]], arr[next[v.second]]);
    prev[next[v.second]] = prev[v.second];
    next[prev[v.second]] = next[v.second];
  }
  std::cout << ans << '\n';
}
