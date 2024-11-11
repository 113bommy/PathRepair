#include <bits/stdc++.h>
using namespace std;
struct Bug {
  int a, id;
} B[100005];
struct Stu {
  int b, c, id;
  bool operator<(const Stu &A) const { return c > A.c; }
} S[100005];
int n, m, s;
int ans[100005];
int ans1[100005];
bool cmp(Bug A, Bug B) { return A.a > B.a; }
bool cmp1(Stu A, Stu B) { return A.b > B.b; }
bool check(int k) {
  int cost = s;
  int l = 0, r = 0;
  priority_queue<Stu> P;
  while (l < m) {
    while (r < n && S[r].b >= B[l].a) {
      P.push(S[r++]);
    }
    Stu T;
    if (P.size())
      T = P.top(), P.pop();
    else {
      return false;
    }
    cost -= T.c;
    if (cost < 0) return false;
    for (int i = l; i < l + k && i < m; i++) ans1[B[i].id] = T.id + 1;
    l += k;
  }
  for (int i = 0; i < m; i++) ans[i] = ans1[i];
  return true;
}
int main() {
  scanf("%d%d%d", &n, &m, &s);
  int Max = 0, Min = 0;
  for (int i = 0; i < m; i++) {
    scanf("%d", &B[i].a);
    B[i].id = i;
    if (B[i].a > Min) Min = B[i].a;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i].b);
    S[i].id = i;
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &S[i].c);
    if (S[i].b > Max && S[i].c <= s) Max = S[i].b;
  }
  sort(B, B + m, cmp);
  sort(S, S + n, cmp1);
  int l = 1, r = m + 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (check(m))
      r = m;
    else
      l = m + 1;
  }
  if (Max < Min)
    puts("NO");
  else {
    puts("YES");
    for (int i = 0; i < m; i++) printf("%d ", ans[i]);
    puts("");
  }
  return 0;
}
