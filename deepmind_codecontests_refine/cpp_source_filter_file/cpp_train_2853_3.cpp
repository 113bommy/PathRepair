#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > ans;
int n, a[1010];
void read(int &x) {
  char ch = getchar();
  int mark = 1;
  for (; ch != '-' && (ch < '0' || ch > '9'); ch = getchar())
    ;
  if (ch == '-') mark = -1, ch = getchar();
  for (x = 0; ch >= '0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - 48;
  x *= mark;
}
void Solve(int &p1, int &p2, int &p3) {
  for (;;) {
    if (a[p1] > a[p2]) swap(p1, p2);
    if (a[p2] > a[p3]) swap(p2, p3);
    if (a[p1] > a[p2]) swap(p1, p2);
    if (a[p1] == 0) break;
    int Q = a[p2] / a[p1];
    while (Q) {
      if (Q & 1)
        a[p2] -= a[p1], a[p1] <<= 1, ans.push_back(make_pair(p1, p2));
      else
        a[p3] -= a[p1], a[p1] <<= 1, ans.push_back(make_pair(p1, p3));
      Q >>= 1;
    }
  }
}
int main() {
  read(n);
  int s = 0;
  for (int i = 1; i <= n; i++) read(a[i]), s += (bool)a[i];
  if (s == 1) {
    printf("-1\n");
    return 0;
  }
  int p1 = 0, p2 = 0;
  for (int i = 1; i <= n; i++)
    if (a[i]) {
      if (p1 == 0)
        p1 = i;
      else if (p2 == 0)
        p2 = i;
      else {
        int t = i;
        Solve(t, p1, p2);
      }
    }
  printf("%d\n", (int)ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d\n", ans[i].first, ans[i].second);
  return 0;
}
