#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:336777216")
using namespace std;
const int MAXN = 50000 + 10;
int N;
int A[MAXN];
int order[MAXN], ans[MAXN];
long long P[MAXN];
bool cmp(const int& i, const int& j) { return P[i] < P[j]; }
void Work() {
  scanf("%d", &N);
  for (int i = 0; i < N; i++) scanf("%d", &A[i]);
  for (int i = 0; i < N; i++)
    P[i] = (long long)A[i] + (long long)A[(i + 1) % N];
  for (int i = 0; i < N; i++) order[i] = i;
  sort(order, order + N, cmp);
  for (int i = 0; i < N; i++) ans[order[i]] = i;
  for (int i = 0; i < N - 1; i++) printf("%d ", ans[i]);
  printf("%d\n", ans[N - 1]);
}
int main() {
  Work();
  return 0;
}
