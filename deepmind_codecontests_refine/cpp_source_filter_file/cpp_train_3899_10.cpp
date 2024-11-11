#include <bits/stdc++.h>
using namespace std;
int main() {
  int trees, daily_limit;
  cin >> trees >> daily_limit;
  vector<list<int>> q(3000);
  for (int i = 0; i < trees; ++i) {
    int day, fruit;
    cin >> day >> fruit;
    q[day - 1].emplace_back(fruit);
  }
  int collected = 0;
  int limit, next_limit = 0;
  for (auto i : q) {
    limit = next_limit;
    for (auto j : i) {
      limit += j;
    }
    collected += min(limit, daily_limit);
    next_limit = min(max(limit - daily_limit, 0), daily_limit);
  }
  cout << collected;
}
