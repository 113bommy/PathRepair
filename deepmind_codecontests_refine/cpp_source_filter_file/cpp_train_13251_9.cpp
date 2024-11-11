#include <bits/stdc++.h>
using namespace std;
void multi(vector<int> &a, int pos, int num) {
  int n = a.size();
  a.resize(n + num);
  for (int j = n - 1; j >= pos; j--) a[j + num] = a[j];
  for (int j = pos; j < pos + num; j++) a[j] = a[pos + num];
}
int main() {
  int a, b, c, d;
  while (scanf("%d%d%d%d", &a, &b, &c, &d) >= 1) {
    if (a < c || a < d || b < c || b < d) {
      printf("-1\n");
      continue;
    }
    if (c == d) {
      int num = c + d + 1;
      if (a + b < num) {
        printf("-1\n");
        continue;
      }
      int topr[2] = {4, 7};
      if (a < b) swap(topr[0], topr[1]), swap(a, b);
      vector<int> ans;
      for (int i = 0; i < num; i++) ans.push_back(topr[i & 1]);
      a = a - (c + 1);
      b = b - c;
      if (topr[0] > topr[1]) swap(topr[0], topr[1]), swap(a, b);
      for (int i = 0; i < (int)ans.size(); i++)
        if (topr[0] == ans[i]) {
          multi(ans, i, a);
          break;
        }
      for (int i = (int)ans.size() - 1; i >= 0; i--)
        if (topr[1] == ans[i]) {
          multi(ans, i, b);
          break;
        }
      for (int i = 0; i < (int)ans.size(); i++) printf("%d", ans[i]);
      printf("\n");
      continue;
    }
    if (abs(c - d) > 1) {
      printf("-1\n");
      continue;
    }
    int topr[2] = {4, 7};
    if (c < d) swap(c, d), swap(a, b), swap(topr[0], topr[1]);
    vector<int> ans;
    for (int i = 0; i < 2 * c; i++) ans.push_back(topr[i & 1]);
    a -= c, b -= c;
    if (topr[0] > topr[1]) swap(topr[0], topr[1]), swap(a, b);
    for (int i = 0; i < (int)ans.size(); i++)
      if (topr[0] == ans[i]) {
        multi(ans, i, a);
        break;
      }
    for (int i = (int)ans.size() - 1; i >= 0; i--)
      if (topr[1] == ans[i]) {
        multi(ans, i, b);
        break;
      }
    for (int i = 0; i < (int)ans.size(); i++) printf("%d", ans[i]);
    printf("\n");
  }
  return 0;
}
