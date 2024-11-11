#include <bits/stdc++.h>
using namespace std;
int n, m, s, headstu, headbug, ans[100000];
struct students {
  int v, s, dy;
  bool operator<(const students &a) const { return v < a.v; }
} stu[100000];
struct cmp {
  bool operator()(students &x, students &y) { return x.s > y.s; }
};
struct bugs {
  int v, dy;
} bug[100000];
void exchange(int &a, int &b) {
  int c = a;
  a = b;
  b = c;
}
bool cmp1(students a, students b) { return a.v > b.v; }
bool cmp2(bugs a, bugs b) { return a.v > b.v; }
void read(int &x) {
  bool flag = false;
  x = 0;
  char ch;
  ch = getchar();
  while (ch == ' ' || ch == '\n') ch = getchar();
  if (ch == '-') flag = true, ch = getchar();
  while (ch != ' ' && ch != '\n') {
    x = x * 10 + ch - '0';
    if (scanf("%c", &ch) == EOF) break;
  }
  if (flag) x = -x;
}
void init() {
  read(n);
  read(m);
  read(s);
  for (int i = 1; i <= m; i++) {
    read(bug[i].v);
    bug[i].dy = i;
  }
  for (int i = 1; i <= n; i++) {
    read(stu[i].v);
    stu[i].dy = i;
  }
  for (int i = 1; i <= n; i++) read(stu[i].s);
}
bool can(int day) {
  priority_queue<students, vector<students>, cmp> heap;
  int totcost = 0;
  headstu = 1;
  headbug = 1;
  while (headbug <= m) {
    while (stu[headstu].v >= bug[headbug].v && headstu <= n) {
      heap.push(stu[headstu]);
      headstu++;
    }
    if (heap.empty()) return false;
    students whotoeat = heap.top();
    heap.pop();
    for (int i = headbug; i < headbug + day && i <= m; i++)
      ans[bug[i].dy] = whotoeat.dy;
    headbug += day;
    totcost += whotoeat.s;
    if (totcost > s) return 0;
  }
  return 1;
}
int main() {
  init();
  sort(stu + 1, stu + n + 1, cmp1);
  sort(bug + 1, bug + m + 1, cmp2);
  int l = 1, r = m * 2, mid;
  while (l < r) {
    mid = (l + r) >> 1;
    if (mid > m) {
      puts("NO");
      return 0;
    }
    if (can(mid))
      r = mid;
    else
      l = mid + 1;
  }
  if (can(l)) {
    puts("YES");
    for (int i = 1; i <= m; i++) printf("%d ", ans[i]);
  } else
    puts("NO");
  return 0;
}
