#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  vector<int> v;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf(" %d", &x);
    v.push_back(x);
  }
  long long s = 0;
  for (auto x : v) {
    s += x;
  }
  long long r = 0;
  for (size_t i = 0; i < v.size(); ++i) {
    r += v[i];
    if (r >= s / 2) {
      printf("%lu\n", i + 1);
      return 0;
    }
  }
  return 0;
}
