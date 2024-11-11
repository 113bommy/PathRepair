#include <bits/stdc++.h>
using namespace std;
int n;
struct Node {
  long long x, y;
  bool operator<(const Node &res) const {
    return x < res.x || x == res.x && y > res.y;
  }
} A[100005];
int Q[100005];
bool check(int a, int b, int c) {
  return (A[c].x - A[b].x) * (A[b].y - A[a].y) <=
         (A[c].y - A[b].y) * (A[b].x - A[a].x);
}
int Calc() {
  long long ret = 0, L = 0, R = -1;
  for (int i = 1; i <= n; i++) {
    if (i > 1 && A[i].x == A[i - 1].x) continue;
    while (L < R && check(Q[R - 1], Q[R], i)) R--;
    Q[++R] = i;
  }
  return R;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld%lld", &A[i].x, &A[i].y);
    A[i].y -= A[i].x * A[i].x;
  }
  sort(A + 1, A + 1 + n);
  int Ans = Calc();
  printf("%d\n", Ans);
  return 0;
}
