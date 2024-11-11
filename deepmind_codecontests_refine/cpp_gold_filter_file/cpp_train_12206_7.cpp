#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(void) {
  int n;
  scanf("%d", &n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    sum += a[i];
  }
  vector<int> ans;
  for (int i = 0; i < n; i++) {
    if (sum == a[i] * n) ans.push_back(i);
  }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < (int)ans.size(); i++) printf("%d ", ans[i] + 1);
  puts("");
  return 0;
}
