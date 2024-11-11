#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[101];
  scanf("%d", &n);
  vector<int> ans;
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int m[] = {0, 0, 0};
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      ans.push_back(a[i]);
    }
    if (a[i] == 100 && m[2] == 0) {
      ans.push_back(a[i]);
      m[2] = 1;
    }
    if (a[i] > 0 && a[i] < 100 && a[i] % 10 == 0 && m[1] == 0) {
      ans.push_back(a[i]);
      m[1] = 1;
    }
  }
  if (ans.size() == 0) {
    printf("1\n%d", a[0]);
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > 0 && a[i] < 10 && m[0] == 0) {
      ans.push_back(a[i]);
      m[0] = 1;
      break;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] > 9 && a[i] < 100 && m[0] == 0 && m[1] == 0) {
      ans.push_back(a[i]);
      break;
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); ++i) printf("%d ", ans[i]);
  return 0;
}
