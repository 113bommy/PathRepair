#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5, maxk = 1e4 + 5;
int N, M, K, V[maxn], pos[maxn], P[maxk], n;
unsigned long long H, X[maxn], f[maxk], KK[25];
vector<pair<unsigned long long, int> > A[maxk];
priority_queue<pair<int, int> > heap;
void Dij() {
  priority_queue<pair<unsigned long long, int>,
                 vector<pair<unsigned long long, int> >,
                 greater<pair<unsigned long long, int> > >
      heap;
  memset(f, 127, sizeof f);
  f[1] = 1;
  heap.push(pair<unsigned long long, int>(1, 1));
  while (!heap.empty()) {
    while (!heap.empty() && heap.top().first > f[heap.top().second]) heap.pop();
    if (heap.empty()) break;
    int x(heap.top().second);
    heap.pop();
    for (int i = 1; i <= n; i++) {
      int y((x + KK[i]) % K);
      if (f[y] > f[x] + KK[i]) {
        f[y] = f[x] + KK[i];
        heap.push(pair<unsigned long long, int>(f[y], y));
      }
    }
  }
}
int main() {
  scanf("%I64u%d%d%d", &H, &N, &M, &K);
  for (int i = 1; i <= N; i++) {
    scanf("%I64u%d", &X[i], &V[i]);
    A[X[i] % K].push_back(pair<unsigned long long, int>(X[i], i));
    if (X[i] % K == 1) heap.push(pair<int, int>(V[i], -i));
  }
  for (int i = 0; i < K; i++) {
    sort(A[i].begin(), A[i].end());
    for (int j = 0; j < A[i].size(); j++) pos[A[i][j].second] = j;
    P[i] = A[i].size();
  }
  memset(f, 127, sizeof f);
  f[1] = 1, P[1] = 0;
  while (M--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      unsigned long long x;
      scanf("%I64u", &x);
      KK[++n] = x;
      Dij();
      for (int i = 0; i < K; i++)
        for (; P[i] && A[i][P[i] - 1].first >= f[i]; P[i]--)
          heap.push(
              pair<int, int>(V[A[i][P[i] - 1].second], -A[i][P[i] - 1].second));
    } else if (t == 2) {
      int x, y;
      scanf("%d%d", &x, &y);
      V[x] -= y;
      if (pos[x] >= P[X[x] % K]) heap.push(pair<int, int>(V[x], -x));
    } else {
      while (!heap.empty() && heap.top().first > V[-heap.top().second])
        heap.pop();
      if (heap.empty())
        puts("0");
      else {
        int x = -heap.top().second;
        printf("%d\n", V[x]), heap.pop();
        V[x] = 0;
      }
    }
  }
  return 0;
}
