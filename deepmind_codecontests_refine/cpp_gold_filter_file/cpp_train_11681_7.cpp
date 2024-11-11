#include <bits/stdc++.h>
const int maxn = 1005;
long long area[maxn];
std::vector<int> pos, neg;
std::vector<int> ans;
bool cmp(int a, int b) { return area[a] < area[b]; }
void solve(std::vector<int> &v, int x) {
  if (v.size() == 0) {
    ans.push_back(x);
    return;
  }
  int max_idx = v[0];
  for (int i = 1; i < v.size(); i++) {
    if (area[v[i]] > area[max_idx]) {
      max_idx = v[i];
    }
  }
  std::vector<int> first, last;
  for (int i = 0; i < v.size(); i++) {
    if (max_idx != v[i]) {
      printf("2 %d %d %d\n", x, max_idx, v[i]);
      fflush(stdout);
      int sign;
      scanf("%d", &sign);
      if (sign > 0)
        first.push_back(v[i]);
      else
        last.push_back(v[i]);
    }
  }
  std::sort(first.begin(), first.end(), cmp);
  std::sort(last.begin(), last.end(), cmp);
  std::reverse(last.begin(), last.end());
  ans.push_back(x);
  for (int i = 0; i < first.size(); i++) ans.push_back(first[i]);
  ans.push_back(max_idx);
  for (int i = 0; i < last.size(); i++) ans.push_back(last[i]);
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 3; i <= n; i++) {
    printf("2 1 2 %d\n", i);
    fflush(stdout);
    int sign;
    scanf("%d", &sign);
    if (sign > 0)
      pos.push_back(i);
    else
      neg.push_back(i);
    printf("1 1 2 %d\n", i);
    fflush(stdout);
    scanf("%I64d", &area[i]);
  }
  solve(pos, 1);
  solve(neg, 2);
  std::reverse(ans.begin(), ans.end());
  printf("0");
  int st = -1;
  for (int i = 0; i < ans.size(); i++) {
    if (ans[i] == 1) st = i;
  }
  for (int i = st; i < ans.size(); i++) {
    printf(" %d", ans[i]);
  }
  for (int i = 0; i < st; i++) {
    printf(" %d", ans[i]);
  }
  printf("\n");
  fflush(stdout);
  return 0;
}
