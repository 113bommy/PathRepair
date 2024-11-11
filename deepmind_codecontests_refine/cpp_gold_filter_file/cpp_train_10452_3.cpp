#include <bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;
const long long INF = 1ll << 60;
const double Inf = 1e20;
const double eps = 1e-9;
void gmax(int &a, int b) { a = (a > b ? a : b); }
void gmin(int &a, int b) { a = (a < b ? a : b); }
const int maxn = 100050;
struct node {
  int a, b, id;
} p[maxn];
int N, P, K;
map<int, int> MP;
bool cmp1(node a, node b) {
  return a.a != b.a ? a.a > b.a : (a.b != b.b ? a.b > b.b : a.id > b.id);
}
bool cmp2(node a, node b) {
  return a.b != b.b ? a.b < b.b : (a.a != b.a ? a.a > b.a : a.id > b.id);
}
int main() {
  scanf("%d%d%d", &N, &P, &K);
  for (int i = 1; i <= N; ++i) scanf("%d%d", &p[i].a, &p[i].b), p[i].id = i;
  sort(p + 1, p + N + 1, cmp2);
  for (int i = 1; i <= N; ++i) MP[p[i].id] = i;
  sort(p + P - K + 1, p + N + 1, cmp1);
  int mx = inf;
  for (int i = P - K + 1; i <= P; ++i) {
    printf("%d ", p[i].id);
    mx = min(mx, MP[p[i].id]);
  }
  sort(p + 1, p + N + 1, cmp2);
  for (int i = mx - 1; i >= mx - (P - K); --i) printf("%d ", p[i].id);
  return 0;
}
