#include <bits/stdc++.h>
using namespace std;
struct Node {
  int s, e, flag, mx;
} Member[4 * 1000010];
int cnt[510000];
vector<int> word[510000];
void Build(int u, int st, int ed) {
  Member[u].s = st;
  Member[u].e = ed;
  Member[u].flag = Member[u].mx = 0;
  if (st + 1 == ed) return;
  Build((u << 1), st, ((st + ed) >> 1));
  Build(((u << 1) + 1), ((st + ed) >> 1), ed);
}
void push_down(int u) {
  if (!Member[u].flag) return;
  Member[(u << 1)].mx += Member[u].flag;
  Member[((u << 1) + 1)].mx += Member[u].flag;
  Member[(u << 1)].flag += Member[u].flag;
  Member[((u << 1) + 1)].flag += Member[u].flag;
  Member[u].flag = 0;
}
void push_up(int u) {
  Member[u].mx = max(Member[(u << 1)].mx, Member[((u << 1) + 1)].mx);
}
void Update(int u, int st, int ed) {
  st = max(st, Member[u].s);
  ed = min(ed, Member[u].e);
  if (st >= ed) return;
  if (Member[u].s == st && Member[u].e == ed) {
    Member[u].mx++;
    Member[u].flag++;
    return;
  }
  push_down(u);
  Update((u << 1), st, ed);
  Update(((u << 1) + 1), st, ed);
  push_up(u);
}
int find(int u, int val) {
  if (Member[u].mx < val) return -1;
  if (Member[u].s + 1 == Member[u].e) return Member[u].s;
  push_down(u);
  if (Member[(u << 1)].mx == val) return find((u << 1), val);
  return find(((u << 1) + 1), val);
}
int main() {
  int n, c, r;
  scanf("%d%d", &n, &c);
  Build(1, 0, c);
  for (int i = 0; i < n; i++) {
    scanf("%d", &cnt[i]);
    for (int j = 0; j < cnt[i]; j++) {
      scanf("%d", &r);
      word[i].push_back(r);
    }
  }
  for (int i = 1; i < n; i++) {
    int len = min(cnt[i], cnt[i - 1]), j;
    for (j = 0; j < len; j++) {
      if (word[i][j] != word[i - 1][j]) break;
    }
    if (j == len) {
      if (cnt[i] >= cnt[i - 1]) Update(1, 0, c);
    } else {
      if (word[i][j] > word[i - 1][j])
        Update(1, 0, c - word[i][j] + 1), Update(1, c - word[i - 1][j] + 1, c);
      else
        Update(1, c - word[i - 1][j] + 1, c - word[i][j] + 1);
    }
  }
  printf("%d\n", find(1, n - 1));
  return 0;
}
