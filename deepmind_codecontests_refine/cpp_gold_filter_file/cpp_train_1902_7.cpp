#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int t;
  scanf(" %d", &t);
  while (t--) {
    int n;
    scanf(" %d", &n);
    unordered_map<int, int> H;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf(" %d", &a);
      ++H[a];
    }
    int biggest = INT_MIN;
    for (auto &x : H) {
      if (x.second > biggest) biggest = x.second;
    }
    int count = 0;
    for (auto &x : H) {
      if (x.second == biggest) {
        ++count;
      }
    }
    int res = (n - count) / (biggest - 1) - 1;
    printf("%d\n", res);
  }
  return 0;
}
