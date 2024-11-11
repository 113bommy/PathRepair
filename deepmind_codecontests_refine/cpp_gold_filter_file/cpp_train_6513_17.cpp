#include <bits/stdc++.h>
const int MAXN = 500001;
int n, a, b, k, t;
char s[MAXN];
std::pair<int, int> q[MAXN];
int main() {
  scanf("%d%d%d%d", &n, &a, &b, &k);
  scanf("%s", s + 1);
  s[n + 1] = '1';
  for (int i = 1, pre = 0; i <= n + 1; i++) {
    if (s[i] == '1') {
      if (pre + 1 <= i - 1) {
        q[++t] = std::make_pair(pre + 1, i - 1);
      }
      pre = i;
    }
  }
  int s = 0;
  for (int i = 1; i <= t; i++) {
    s += (q[i].second - q[i].first + 1) / b;
  }
  std::vector<int> answer;
  while (s >= a) {
    std::pair<int, int> top = q[t--];
    if (top.second - top.first + 1 < b) continue;
    answer.push_back(top.first + b - 1);
    top.first += b;
    q[++t] = top;
    s--;
  }
  printf("%d\n", (int)answer.size());
  for (int i = 0; i < (int)answer.size(); i++) {
    printf("%d%c", answer[i], " \n"[i + 1 == (int)answer.size()]);
  }
  return 0;
}
