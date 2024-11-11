#include <bits/stdc++.h>
using namespace std;
const int N = 100000 + 5;
int n;
int main() {
  scanf("%d", &n);
  int res = 1e9;
  int ans = 1e9;
  for (int i = 1; i <= n; ++i) {
    if (res > i + (n + i - 1) / i) {
      res = i + (n + i - 1) / i;
      ans = i;
    }
  }
  vector<int> v;
  vector<int> tmp;
  for (int i = 0, x; i < n; ++i) {
    x = i + 1;
    tmp.push_back(x);
    if (x % ans == 0 || i == n - 1) {
      reverse(tmp.begin(), tmp.end());
      v.insert(v.end(), tmp.begin(), tmp.end());
      tmp.clear();
    }
  }
  reverse(v.begin(), v.end());
  for (auto x : v) printf("%d ", x);
  puts("");
  return 0;
}
