#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long double eps = 1e-14;
const int N = 1e5 + 5;
int read() {
  int s = 0, f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    s = s * 10 + c - '0';
    c = getchar();
  }
  return s * f;
}
int K, n, m, a[N], op[N];
struct Node {
  long double x;
  int id;
  friend bool operator<(Node A, Node B) {
    return fabs(A.x - B.x) < eps ? op[A.id] < op[B.id] : A.x > B.x;
  }
} C[N];
vector<Node> Mul, Add[N], Ans;
bool cmp(Node A, Node B) {
  return op[A.id] != op[B.id] ? op[A.id] < op[B.id] : A.x > B.x;
}
int main() {
  K = read();
  n = read();
  m = read();
  for (int i = 1; i <= K; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    op[i] = read();
    int x = read(), y = read();
    Node tmp = (Node){(long double)y, i};
    if (op[i] == 1) C[x] = min(C[x], tmp);
    if (op[i] == 2) Add[x].push_back(tmp);
    if (op[i] == 3) Mul.push_back(tmp);
  }
  for (int i = 1; i <= n; i++) {
    if (C[i].x > a[i]) Add[i].push_back((Node){C[i].x - a[i], C[i].id});
  }
  for (int i = 1; i <= n; i++) {
    long double tmp = a[i];
    sort(Add[i].begin(), Add[i].end());
    for (auto t : Add[i]) {
      Mul.push_back((Node){(tmp + t.x) / tmp, t.id});
      tmp += t.x;
    }
  }
  sort(Mul.begin(), Mul.end());
  int num = min(m, (int)Mul.size());
  for (int i = 0; i < num; i++) Ans.push_back(Mul[i]);
  sort(Ans.begin(), Ans.end(), cmp);
  printf("%d\n", num);
  for (auto ans : Ans) printf("%d ", ans.id);
  return 0;
}
