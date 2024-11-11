#include <bits/stdc++.h>
#pragma GCC optimize("O2")
using namespace std;
const int N = 1e6 + 10;
const long long mod = 1e9 + 7;
const long long mod2 = 998244353;
const long long inf = 8e18;
const int LOG = 22;
long long pw(long long a, long long b, long long M) {
  return (!b ? 1
             : (b & 1 ? (a * pw(a * a % M, b / 2, M)) % M
                      : pw(a * a % M, b / 2, M)));
}
vector<vector<int> > T, first;
void add(int x) {
  T.push_back({x + 1, x + 2, x + 3});
  T.push_back({x + 2, x + 3, x + 4});
  T.push_back({x + 3, x + 4, x + 1});
  T.push_back({x + 4, x + 1, x + 2});
}
int main() {
  int n;
  scanf("%d", &n);
  if (n & 1) {
    T.push_back({1, 2, 3});
    for (int i = 5; i <= n; i += 2) {
      T.push_back({1, i - 1, i});
      for (int j = 2; j < i - 1; j += 2) {
        first.push_back({j, i - 1, j + 1, i});
      }
    }
    printf("%d\n", ((int)T.size() + (int)first.size()) * 2);
    for (auto x : T) {
      printf("3 %d %d %d\n", x[0], x[1], x[2]);
      printf("3 %d %d %d\n", x[0], x[1], x[2]);
    }
    for (auto x : first) {
      printf("4 %d %d %d %d\n", x[0], x[1], x[2], x[3]);
      printf("4 %d %d %d %d\n", x[0], x[1], x[2], x[3]);
    }
    return 0;
  }
  if (n % 4 == 0) {
    add(0);
    for (int i = 8; i <= n; i += 4) {
      add(i - 4);
      for (int j = 2; j <= i - 4; j += 2) {
        first.push_back({i - 3, j - 1, i - 2, j});
        first.push_back({i - 3, j - 1, i - 2, j});
        first.push_back({i - 1, j - 1, i, j});
        first.push_back({i - 1, j - 1, i, j});
      }
    }
  } else {
    T.push_back({1, 2, 3});
    T.push_back({1, 2, 4});
    T.push_back({2, 3, 4});
    T.push_back({1, 3, 4});
    T.push_back({5, 6, 1});
    T.push_back({5, 6, 2});
    first.push_back({1, 5, 2, 6});
    first.push_back({3, 5, 4, 6});
    first.push_back({3, 5, 4, 6});
    for (int i = 10; i <= n; i += 4) {
      add(i - 4);
      for (int j = 2; j <= i - 4; j += 2) {
        first.push_back({i - 3, j - 1, i - 2, j});
        first.push_back({i - 3, j - 1, i - 2, j});
        first.push_back({i - 1, j - 1, i, j});
        first.push_back({i - 1, j - 1, i, j});
      }
    }
  }
  printf("%d\n", (int)T.size() + (int)first.size());
  for (auto x : T) {
    printf("3 %d %d %d\n", x[0], x[1], x[2]);
  }
  for (auto x : first) {
    printf("4 %d %d %d %d\n", x[0], x[1], x[2], x[3]);
  }
  return 0;
}
