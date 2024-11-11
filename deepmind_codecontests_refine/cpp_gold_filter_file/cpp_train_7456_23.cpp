#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
char ch[maxn];
int sum[maxn], dp[maxn];
vector<int> v;
bool check(int f, int s, int mid) {
  int t = max(0, v[f] - mid - 1), flag = 1;
  if (sum[t] > sum[dp[s]]) flag = 0;
  return flag;
}
int main() {
  int n, cnt = 0, local, last;
  v.push_back(0);
  scanf("%d", &n);
  scanf("%s", ch + 1);
  for (int i = 1; i <= n; i++) {
    if (ch[i] == '*')
      sum[i] = sum[i - 1] + 1, last = i;
    else
      sum[i] = sum[i - 1];
    if (ch[i] == 'P') {
      cnt++, local = i;
      v.push_back(i);
    }
  }
  if (cnt == 1) {
    int ans = 0, ans1 = 0, value = 0, value1 = 0;
    for (int i = local; i > 0; i--)
      if (ch[i] == '*') ans = local - i, value++;
    for (int i = local; i <= n; i++)
      if (ch[i] == '*') ans1 = i - local, value1++;
    if (value == value1)
      printf("%d %d\n", value, min(ans, ans1));
    else if (value > value1)
      printf("%d %d\n", value, ans);
    else
      printf("%d %d\n", value1, ans1);
    return 0;
  }
  int ss = v.size() - 1;
  int l = 0, r = n, ans = n;
  while (l < r) {
    int mid = (l + r) / 2, flag = 1;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i < v.size(); i++) {
      if (!check(i, i - 1, mid)) break;
      dp[i] = v[i];
      if (i != 1 && check(i, i - 2, mid))
        dp[i] = max(min(v[i - 1] + mid, n), dp[i]);
      if (sum[v[i]] <= sum[dp[i - 1]]) dp[i] = max(min(v[i] + mid, n), dp[i]);
    }
    if (dp[ss] >= last)
      ans = mid, r = mid;
    else
      l = mid + 1;
  }
  printf("%d %d\n", sum[last], ans);
  return 0;
}
