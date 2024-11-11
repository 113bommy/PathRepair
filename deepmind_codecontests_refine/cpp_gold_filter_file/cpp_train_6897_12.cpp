#include <bits/stdc++.h>
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f;
int n, m, k;
struct books {
  int t, id;
  bool operator<(const books &w) const { return t < w.t; }
} A[N], B[N], C[N], D[N];
int main() {
  cin >> n >> m >> k;
  int a = 0, b = 0, c = 0, d = 0;
  for (int i = 1; i <= n; i++) {
    int first, second, z;
    cin >> first >> second >> z;
    if (second && z)
      C[++c] = {first, i};
    else if (second)
      A[++a] = {first, i};
    else if (z)
      B[++b] = {first, i};
    else
      D[++d] = {first, i};
  }
  sort(A + 1, A + 1 + a);
  sort(B + 1, B + 1 + b);
  sort(C + 1, C + 1 + c);
  sort(D + 1, D + 1 + d);
  int ai = 0, bi = 0, ci = 0, di = 0;
  int ans = 0;
  while (ci < c && ci < k) ans += C[++ci].t;
  while (ai + ci < k && ai < a && bi < b) ans += A[++ai].t + B[++bi].t;
  if (ai + ci < k || ai + bi + ci > m) {
    puts("-1");
    return 0;
  }
  while (ai + bi + ci + di < m) {
    int op1, op2, op3, op4, op5, minv;
    op1 = op2 = op3 = op4 = op5 = INF;
    if (ci && ai < a && bi < b) op1 = A[ai + 1].t + B[bi + 1].t - C[ci].t;
    if (ai < a) op2 = A[ai + 1].t;
    if (bi < b) op3 = B[bi + 1].t;
    if (ci < c) op4 = C[ci + 1].t;
    if (di < d) op5 = D[di + 1].t;
    minv = min(min(min(min(op1, op2), op3), op4), op5);
    if (minv == INF) break;
    if (minv == op1)
      ai++, bi++, ci--;
    else if (minv == op2)
      ai++;
    else if (minv == op3)
      bi++;
    else if (minv == op4)
      ci++;
    else if (minv == op5)
      di++;
    ans += minv;
  }
  cout << ans << endl;
  for (int i = 1; i <= ai; i++) cout << A[i].id << ' ';
  for (int i = 1; i <= bi; i++) cout << B[i].id << ' ';
  for (int i = 1; i <= ci; i++) cout << C[i].id << ' ';
  for (int i = 1; i <= di; i++) cout << D[i].id << ' ';
  cout << endl;
  return 0;
}
