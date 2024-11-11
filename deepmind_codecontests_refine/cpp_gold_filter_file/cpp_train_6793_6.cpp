#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 5;
int a[N];
vector<int> ans;
int main() {
  int n, p;
  scanf("%d%d", &n, &p);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= 2000; i++) {
    int flag = 0;
    for (int j = n; j >= 1; j--) {
      if (i + j - 1 < a[j]) {
        flag = 1;
      }
    }
    if (flag) {
      continue;
    }
    int cnt = 1;
    for (int j = n; j >= 1; j--) {
      int dis = (i + j - 1) - a[j] + 1;
      cnt *= min(dis, j);
      cnt %= p;
    }
    if (cnt > 0) {
      ans.push_back(i);
    }
  }
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++) {
    printf("%d ", ans[i]);
  }
}
