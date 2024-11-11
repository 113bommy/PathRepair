#include <bits/stdc++.h>
using namespace std;
int f(int x) {
  int r = x;
  while (x != 0) r += x % 10, x /= 10;
  return r;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<int> r;
  for (int i = max(n - 100, 0); i < n; ++i)
    if (f(i) == n) r.push_back(i);
  printf("%d\n", r.size());
  for (int i : r) printf("%d\n", i);
}
