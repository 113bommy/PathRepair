#include <bits/stdc++.h>
using namespace std;
vector<int> ans[222];
int main() {
  int n;
  scanf("%d", &n);
  int lb = 1, rb = n + 1;
  for (int mid = (lb + rb) / 2; lb < rb - 1; mid = (lb + rb) / 2)
    if (mid * (mid - 1) / 2 <= n)
      lb = mid;
    else
      rb = mid;
  printf("%d\n", lb);
  for (int i = 1; i <= lb; i++)
    for (int j = i + 1; j <= lb; j++) {
      static int idx = 0;
      ans[i].push_back(++idx);
      ans[j].push_back(idx);
    }
  for (int i = 1; i <= lb; i++) {
    for (int j = 0; j < (int)ans[i].size(); j++) printf("%d ", ans[i][j]);
    printf("\n");
  }
}
