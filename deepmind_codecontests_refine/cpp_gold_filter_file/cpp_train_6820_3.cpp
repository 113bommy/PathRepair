#include <bits/stdc++.h>
int n, a, b, c;
std::multiset<int> set;
int greedy(std::multiset<int> &set, int nowValue, int nextValue) {
  int ret = 0;
  while (!set.empty()) {
    if (*(--set.end()) <= nextValue) break;
    set.erase(--set.end());
    auto it = set.upper_bound(nowValue);
    if (it != set.begin()) {
      it--;
      set.erase(it);
    }
    ret++;
  }
  return ret;
}
void reduce(std::multiset<int> &set, int nowValue, int a, int b, int c, int &x,
            int &y) {
  int ret = 0;
  auto it = set.upper_bound(nowValue);
  if (it != set.begin()) {
    it--;
    if (*it <= a + b) x--;
    if (*it <= c) y--;
    set.erase(it);
  }
}
int main() {
  std::cin >> n;
  std::cin >> a >> b >> c;
  if (a > b) std::swap(a, b);
  if (a > c) std::swap(a, c);
  if (b > c) std::swap(b, c);
  for (int i = 1; i <= n; i++) {
    int x;
    std::cin >> x;
    set.insert(x);
  }
  if (*(--set.end()) > a + b + c) return puts("-1"), 0;
  int answer = 0;
  while (!set.empty()) {
    if (*(--set.end()) <= b + c) break;
    set.erase(--set.end());
    answer++;
  }
  answer += greedy(set, a, a + c);
  answer += greedy(set, b, std::max(c, a + b));
  int x = 0, y = 0;
  for (auto it = set.begin(); it != set.end(); it++) {
    if (*it <= a + b) x++;
    if (*it <= c) y++;
  }
  int tmp = ~0u >> 2;
  for (int round = 0; round <= n + 5; round++) {
    if (2 * std::min(x, y) >= (int)set.size()) {
      tmp = std::min(tmp, round + ((int)set.size() + 1) / 2);
    } else {
      tmp = std::min(tmp, round + (int)set.size() - std::min(x, y));
    }
    reduce(set, c, a, b, c, x, y);
    reduce(set, b, a, b, c, x, y);
    reduce(set, a, a, b, c, x, y);
  }
  std::cout << answer + tmp << std::endl;
  return 0;
}
