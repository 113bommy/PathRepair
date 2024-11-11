#include <bits/stdc++.h>
using namespace std;
map<int, int> pset;
vector<int> tot;
int check(int n, vector<int>::iterator it) {
  auto i = lower_bound(it, tot.end(), n);
  if (i == tot.end())
    return 0;
  else
    return n + check(n << 1, i + 1);
}
int main() {
  int n, a;
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &a);
    pset[a]++;
  }
  for (auto &i : pset) {
    tot.push_back(i.second);
  }
  sort(tot.begin(), tot.end());
  int ans = 0;
  for (int i = 1; i <= tot.back(); i++) {
    ans = max(ans, check(i, tot.begin()));
  }
  printf("%d\n", ans);
  return 0;
}
