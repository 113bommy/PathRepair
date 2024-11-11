#include <bits/stdc++.h>
using namespace std;
int low[222222], dfn[222222];
bool isused[222222];
vector<int> e[222222];
int top, groupnum, countid;
int st[222222], groupid[222222];
void findgroup(int now) {
  dfn[now] = low[now] = countid++;
  isused[now] = 1;
  st[top++] = now;
  for (auto &p : e[now]) {
    int k = p;
    if (isused[k]) {
      if (!groupid[k]) low[now] = min(low[now], dfn[k]);
      continue;
    }
    findgroup(k);
    low[now] = min(low[now], low[k]);
  }
  if (low[now] == dfn[now]) {
    groupnum++;
    while (1) {
      int x = st[--top];
      groupid[x] = groupnum;
      if (x == now) break;
    }
  }
}
vector<int> e2[222222];
int degree[222222], q[222222], front;
char res[222222];
int num[222222], mmap[222222];
int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &num[i]);
    if (i > 1) e[num[i - 1]].push_back(num[i]);
  }
  for (int i = 1; i < n + 1; i++) {
    scanf("%d", &num[i]);
    if (i > 1) e[num[i - 1]].push_back(num[i]);
  }
  for (int i = 1; i < n + 1; i++)
    if (!isused[i]) findgroup(1);
  if (groupnum < k) {
    printf("NO\n");
    return 0;
  };
  printf("YES\n");
  for (int i = 1; i < n + 1; i++)
    for (int k : e[i])
      if (groupid[i] != groupid[k])
        e2[groupid[i]].push_back(groupid[k]), degree[groupid[k]]++;
  top = 0;
  for (int i = 1; i < groupnum + 1; i++)
    if (!degree[i]) q[top++] = i;
  int x = 'a';
  while (top != front) {
    int k = q[front++];
    mmap[k] = x;
    x = (x == 'z') ? 'z' : x + 1;
    for (int xx : e2[k]) {
      degree[xx]--;
      if (degree[xx] == 0) q[top++] = xx;
    }
  }
  for (int i = 1; i < n + 1; i++) res[i] = mmap[groupid[i]];
  printf("%s\n", res + 1);
}
