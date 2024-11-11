#include <bits/stdc++.h>
using namespace std;
long long z(long long n) {
  long long ans = 0;
  while (n / 5 != 0) {
    ans += n / 5;
    n /= 5;
  }
  return ans;
}
vector<int> ans;
int main() {
  int m;
  scanf("%d", &m);
  for (int i = 1; i < 1000005; i++) {
    if (z(i) == m) {
      ans.push_back(i);
    }
  }
  int sz = ans.size();
  printf("%d\n", sz);
  if (sz) {
    for (int i = 0; i < ans.size(); i++) {
      printf("%d ", ans[i]);
    }
  }
}
