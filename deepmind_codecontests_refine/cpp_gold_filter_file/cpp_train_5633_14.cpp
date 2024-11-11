#include <bits/stdc++.h>
using namespace std;
vector<long long> v;
void dfs(int depth, long long num, int count_) {
  v.push_back(num);
  if (depth == 18) return;
  dfs(depth + 1, num * 10, count_);
  if (count_ < 3) {
    for (int i = 1; i <= 9; i++) dfs(depth + 1, num * 10 + i, count_ + 1);
  }
}
int main() {
  for (int i = 1; i <= 9; i++) dfs(1, i, 1);
  v.push_back(1e18);
  sort(v.begin(), v.end());
  int n;
  scanf("%d", &n);
  while (n--) {
    long long l, r;
    scanf("%lld%lld", &l, &r);
    long long sum =
        upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
    printf("%lld\n", sum);
  }
}
