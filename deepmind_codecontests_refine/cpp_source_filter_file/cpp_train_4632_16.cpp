#include <bits/stdc++.h>
using namespace std;
int n, k, p, x, y, a, b, sum, gey;
vector<int> ans;
int main() {
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  for (int i = 0; i < k; i++) {
    scanf("%d", &a);
    sum += a;
    gey += (a >= y);
  }
  for (int i = gey; i < (n + 1) / 2; i++, k++) {
    ans.push_back(y);
    sum += y;
  }
  for (int i = k; i < n; i++) {
    ans.push_back(1);
    sum += 1;
  }
  if (sum > x)
    printf("-1");
  else
    for (auto it : ans) printf("%d ", it);
  return 0;
}
