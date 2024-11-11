#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  vector<int> ans;
  scanf("%d%d", &n, &k);
  int A = 1, B = n - 1;
  bool flag = false;
  ans.push_back(n);
  while (k > 1) {
    k--;
    if (!flag)
      ans.push_back(A++);
    else
      ans.push_back(B--);
    flag ^= 1;
  }
  if (flag)
    for (int i = A; i <= B; i++) ans.push_back(i);
  else
    for (int i = B; i >= A; i--) ans.push_back(i);
  for (int i = 0; i < (ans.size()); i++) printf("%d ", ans[i]);
  puts("");
  return 0;
}
