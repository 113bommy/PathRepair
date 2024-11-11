#include <bits/stdc++.h>
using namespace std;
vector<int> q[100005];
int n, m, k;
int solve(vector<int> p) {
  int len = p.size();
  int ans = 1;
  int sum = 0;
  int id = 0;
  int res = 1;
  for (int i = 1; i < len; i++) {
    sum += p[i] - p[i - 1] - 1;
    res++;
    while (sum > k) {
      sum -= (p[id + 1] - p[id] - 1);
      res--;
      id++;
    }
    ans = max(res, ans);
  }
  return ans;
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    q[x].push_back(i);
  }
  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = max(ans, solve(q[i]));
  }
  printf("%d\n", ans);
}
