#include <bits/stdc++.h>
using namespace std;
int N, Q, t1, ROOT, P;
long long int tmp, num;
double AVG[100005];
int G[100005][2], V[100005], L[100005], R[100005], B[100005], C[100005],
    MIN = -1, MAX = 1000000005;
vector<int> A;
void rec(int x) {
  if (G[x][0] == G[x][1])
    L[x] = R[x] = V[x];
  else {
    rec(G[x][0]);
    rec(G[x][1]);
    L[x] = L[G[x][0]];
    R[x] = R[G[x][1]];
  }
}
void cal(int x, int a, int b) {
  if (G[x][0] == G[x][1]) {
    A.push_back(x);
    B[x] = a;
    C[x] = b;
    AVG[x] = (long double)(tmp) / (long double)(num);
  } else {
    ++num;
    tmp += (long long int)(L[G[x][1]]);
    cal(G[x][0], a, V[x] - 1);
    tmp += (long long int)(R[G[x][0]]) - (long long int)(L[G[x][1]]);
    cal(G[x][1], V[x] + 1, b);
    tmp -= (long long int)(R[G[x][0]]);
    --num;
  }
}
bool cmp(int a, int b) { return C[a] < B[b]; }
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; ++i) {
    scanf("%d%d", &t1, &V[i]);
    MIN = min(MIN, V[i]);
    MAX = max(MAX, V[i]);
    if (t1 != -1) {
      G[t1][0] = G[t1][1];
      G[t1][1] = i;
    } else
      ROOT = i;
  }
  for (int i = 1; i <= N; ++i)
    if (G[i][0] != G[i][1] && V[G[i][0]] > V[G[i][1]]) swap(G[i][0], G[i][1]);
  rec(ROOT);
  cal(ROOT, MIN, MAX);
  scanf("%d", &Q);
  for (int i = 0; i < Q; ++i) {
    scanf("%d", &B[N + 1]);
    C[N + 1] = B[N + 1];
    P = lower_bound(A.begin(), A.end(), N + 1, cmp) - A.begin();
    printf("%lf\n", AVG[A[P]]);
  }
}
