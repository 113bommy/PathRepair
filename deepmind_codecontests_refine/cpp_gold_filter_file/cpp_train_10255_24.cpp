#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[2222], b[2222], pos[2222];
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    pos[b[i]] = i;
  }
  int res = 0;
  vector<pair<int, int> > ans;
  for (int j = n - 1; j >= 0; j--) {
    for (int i = 0; i < n; i++) {
      if (a[i] == b[j]) {
        int ii = pos[a[i]], i1 = i;
        for (; i <= ii; i++) {
          if (pos[a[i]] < i && pos[a[i]] <= i1) {
            res += abs(i1 - i);
            ans.push_back(pair<int, int>(i1 + 1, i + 1));
            swap(a[i1], a[i]);
            i1 = i;
          }
        }
      }
    }
  }
  printf("%d\n", res);
  printf("%d\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
}
