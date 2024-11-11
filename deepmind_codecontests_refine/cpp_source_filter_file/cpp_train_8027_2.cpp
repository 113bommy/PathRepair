#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<int> a(n);
  for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
  int sum = 0;
  for (int i = 0; i < n; ++i) sum += a[i];
  if (sum % k) {
    printf("NO\n");
    return 0;
  }
  int req = sum / k;
  int cur = 0;
  int len = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] > req) {
      printf("NO\n");
      return 0;
    }
  }
  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    cur += a[i];
    len++;
    if (cur == req) {
      ans.push_back(len);
      cur = 0;
      len = 0;
    } else if (cur > req) {
      cur = a[i];
      len = 1;
    }
  }
  if ((int)ans.size() == k) {
    printf("YES\n");
    for (int i = 0; i < k; ++i) printf("%d ", ans[i]);
  } else {
    printf("NO\n");
  }
  return 0;
}
