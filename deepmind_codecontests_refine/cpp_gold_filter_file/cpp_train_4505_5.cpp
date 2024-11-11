#include <bits/stdc++.h>
int main() {
  int n;
  scanf("%d", &n);
  int64_t total_damage = 0;
  int to_double = 0;
  int zero = 0;
  std::set<std::pair<int, int>> doubled;
  std::set<std::pair<int, int>> pend;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (y > 0) {
      if (x == 1) to_double++;
      total_damage += y;
      pend.insert({y, x});
    } else {
      y = -y;
      total_damage -= y;
      auto it = pend.find({y, x});
      if (it != pend.end()) {
        pend.erase(it);
      } else {
        it = doubled.find({y, x});
        doubled.erase(it);
        if (x == 0) zero--;
        total_damage -= y;
      }
      if (x == 1) {
        to_double--;
        if (doubled.size() > 0) {
          auto it = doubled.begin();
          std::pair<int, int> now = *it;
          if (now.second == 0) zero--;
          doubled.erase(it);
          total_damage -= now.first;
          pend.insert(now);
        }
      }
    }
    if (doubled.size() < to_double && pend.size() > 0) {
      auto it = --pend.end();
      std::pair<int, int> max = *it;
      doubled.insert(max);
      pend.erase(it);
      if (max.second == 0) zero++;
      total_damage += max.first;
    } else if (doubled.size() > 0 && pend.size() > 0) {
      auto it = doubled.begin();
      auto it2 = --pend.end();
      std::pair<int, int> min = *it;
      std::pair<int, int> max = *it2;
      if (max.first > min.first) {
        if (max.second == 0) zero++;
        if (min.second == 0) zero--;
        doubled.erase(it);
        pend.erase(it2);
        doubled.insert(max);
        pend.insert(min);
        total_damage += max.first - min.first;
      }
    }
    if (doubled.size() > 0 && zero == 0 && doubled.size() == to_double) {
      auto it1 = doubled.begin();
      std::pair<int, int> now = *it1;
      doubled.erase(it1);
      total_damage -= now.first;
      if (pend.size() > 0) {
        auto it2 = --pend.end();
        std::pair<int, int> now2 = *it2;
        pend.erase(it2);
        doubled.insert(now2);
        zero++;
        total_damage += now2.first;
      }
      pend.insert(now);
    }
    printf("%lld\n", total_damage);
  }
  return 0;
}
