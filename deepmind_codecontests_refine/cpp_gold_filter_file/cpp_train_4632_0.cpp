#include <bits/stdc++.h>
using namespace std;
const int maxk = 999 + 5;
int a[maxk];
vector<int> vec;
int main() {
  int n, k, p, x, y;
  scanf("%d%d%d%d%d", &n, &k, &p, &x, &y);
  for (int i = 0; i < k; i++) scanf("%d", a + i);
  if (y > p) {
    printf("-1\n");
    return 0;
  }
  sort(a, a + k);
  for (int one = 0, now = 0; one <= n - k; one++) {
    now = 0;
    vec.clear();
    for (int i = 0; i < one; i++) {
      now++;
      vec.push_back(1);
    }
    for (int i = 0; i < k; i++) {
      now += a[i];
      vec.push_back(a[i]);
    }
    for (; vec.size() < n;) {
      vec.push_back(y);
      now += y;
    }
    if (now > x) continue;
    sort(vec.begin(), vec.end());
    if (vec[(n + 1) / 2 - 1] >= y) {
      vector<int> ans;
      for (int i = 0; i < one; i++) ans.push_back(1);
      for (int i = 0; i < n - (one + k); i++) ans.push_back(y);
      for (int i = 0; i < ans.size(); i++)
        printf("%d%c", ans[i], i == ans.size() - 1 ? '\n' : ' ');
      return 0;
    }
  }
  printf("-1\n");
  return 0;
}
