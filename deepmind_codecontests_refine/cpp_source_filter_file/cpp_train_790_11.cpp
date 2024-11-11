#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100005;
char rs[MaxN][9];
int rt[MaxN], rv[MaxN];
int N, E;
bool use[MaxN];
queue<int> que[2];
int rem[2][MaxN];
int rcou[2];
inline int change(const char s[]) {
  int ret = 0;
  for (int i = 0; s[i]; ++i) {
    if (s[i] < '0' || s[i] > '9') return 0;
    if (ret == 0 && s[i] == '0') return 0;
    ret = ret * 10 + s[i] - '0';
  }
  if (ret <= N) return ret;
  return 0;
}
int ans;
char aA[MaxN][9], aB[MaxN][9];
inline void addAns(const char a[], const char b[]) {
  ++ans;
  strcpy(aA[ans], a);
  strcpy(aB[ans], b);
}
inline void addAns(const char a[], int b) {
  char s[9];
  sprintf(s, "%d", b);
  addAns(a, s);
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%s %d", rs[i], rt + i);
    rv[i] = change(rs[i]);
    use[rv[i]] = 1;
    if (rt[i]) ++E;
  }
  for (int i = 1; i <= N; ++i) {
    if (!use[i]) que[i <= E].push(i);
    if (rv[i] == 0) continue;
    if (rv[i] <= E && rt[i] == 0)
      rem[1][rcou[1]++] = i;
    else if (rv[i] > E && rt[i])
      rem[0][rcou[0]++] = i;
  }
  if (rcou[0] == 0 && rcou[1] == 0 && que[0].size() == 0 &&
      que[1].size() == 0) {
    puts("0");
    return 0;
  }
  bool ok = 0;
  int flag;
  if (que[0].size())
    flag = 0;
  else if (que[1].size())
    flag = 1;
  else {
    ok = 1;
    flag = 0;
    addAns(rs[rem[1][rcou[1] - 1]], "whywhy");
    que[1].push(rv[rem[1][rcou[1] - 1]]);
    --rcou[1];
  }
  int pos[2] = {E + 1, 1};
  int t;
  while (1) {
    if (rcou[flag] == 0 && rcou[flag ^ 1] == 0) break;
    if (rcou[flag]) {
      t = rem[flag][rcou[flag] - 1];
      --rcou[flag];
      addAns(rs[t], que[flag ^ 1].front());
      que[flag ^ 1].pop();
      que[flag].push(rv[t]);
    }
    flag ^= 1;
  }
  for (int i = 1; i <= N; ++i)
    if (rv[i] == 0) {
      addAns(rs[i], que[rt[i]].front());
      que[rt[i]].pop();
    }
  if (ok) addAns("whywhy", que[0].size() ? que[0].front() : que[1].front());
  printf("%d\n", ans);
  for (int i = 1; i <= ans; ++i) printf("move %s %s\n", aA[i], aB[i]);
  return 0;
}
