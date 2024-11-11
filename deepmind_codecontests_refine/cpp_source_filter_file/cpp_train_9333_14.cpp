#include <bits/stdc++.h>
using namespace std;
int x, d, ones = 0;
long long int nowd = 1;
vector<long long int> ans;
int main() {
  scanf("%d%d", &x, &d);
  for (int i = 31; i >= 0; i--)
    if ((x >> i) & 1) {
      ++ones;
      for (int j = 1; j <= i; j++) ans.push_back(nowd);
      nowd += d;
    }
  while (ones--) ans.push_back(nowd), nowd += d;
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
  return 0;
}
