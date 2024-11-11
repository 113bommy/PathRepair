#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 200000;
int col[N], di[N];
long long ai[N];
int A[N], B[N], V[N], P[N];
long long S[N];
vector<int> edge[N];
int L;
queue<int> Q;
void dfs(int t, int c) {
  col[t] = c;
  for (int i = 0; i < edge[t].size(); ++i) {
    int b = A[edge[t][i]] + B[edge[t][i]] - t;
    if (col[b] == -1)
      dfs(b, !c);
    else if (col[b] == col[t])
      L = edge[t][i];
  }
}
int fa[N];
int get_f(int t) { return fa[t] = (fa[t] == t ? t : get_f(fa[t])); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%lld", &ai[i]);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &A[i], &B[i]);
    edge[A[i]].push_back(i);
    di[A[i]]++;
    edge[B[i]].push_back(i);
    di[B[i]]++;
  }
  for (int i = 1; i <= n; ++i) col[i] = -1;
  dfs(1, 0);
  if (L) {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    V[L] = 1;
    for (int i = 1; i <= m; ++i)
      if (i != L)
        if (get_f(A[i]) != get_f(B[i]) && col[A[i]] != col[B[i]])
          V[i] = 1, fa[get_f(A[i])] = get_f(B[i]);
    for (int i = 1; i <= m; ++i)
      if (!V[i]) {
        S[i] = 1;
        di[A[i]]--;
        di[B[i]]--;
        ai[A[i]]--;
        ai[B[i]]--;
      }
    for (int i = 1; i <= n; ++i)
      if (di[i] == 1) Q.push(i);
    while (!Q.empty()) {
      int t = Q.front();
      Q.pop();
      for (int i = 0; i < edge[t].size(); ++i)
        if (V[edge[t][i]]) {
          int b = A[edge[t][i]] + B[edge[t][i]] - t;
          if (!di[b]) continue;
          di[t]--;
          di[b]--;
          S[edge[t][i]] = ai[t];
          ai[b] -= ai[t];
          ai[t] = 0;
          if (di[b] == 1) Q.push(b);
        }
    }
    int start = -1;
    for (int i = 1; i <= n; ++i)
      if (di[i] && start == -1) start = i;
    int p = start;
    long long sum = ai[p], k = 1;
    for (int i = 0; i < edge[p].size(); ++i)
      if (V[edge[p][i]]) {
        int q = A[edge[p][i]] + B[edge[p][i]] - p;
        if (di[q]) {
          p = q;
          break;
        }
      }
    for (int o = start; p != start;) {
      sum += k * ai[p];
      for (int i = 0; i < edge[p].size(); ++i)
        if (V[edge[p][i]]) {
          int q = A[edge[p][i]] + B[edge[p][i]] - p;
          if (di[q] && q != o) {
            o = p;
            p = q;
            k *= -1;
            break;
          }
        }
    }
    p = start;
    ai[p] -= sum / 2;
    for (int i = 0; i < edge[p].size(); ++i)
      if (V[edge[p][i]]) {
        int q = A[edge[p][i]] + B[edge[p][i]] - p;
        if (di[q]) {
          S[edge[p][i]] = sum / 2;
          ai[q] -= sum / 2;
          p = q;
          break;
        }
      }
    for (int o = start; p != start;) {
      for (int i = 0; i < edge[p].size(); ++i)
        if (V[edge[p][i]]) {
          int q = A[edge[p][i]] + B[edge[p][i]] - p;
          if (di[q] && q != o) {
            S[edge[p][i]] = ai[p];
            ai[q] -= ai[p];
            o = p;
            p = q;
            break;
          }
        }
    }
    puts("YES");
    for (int i = 1; i <= m; ++i) printf("%lld\n", S[i]);
  } else {
    for (int i = 1; i <= n; ++i) fa[i] = i;
    for (int i = 1; i <= m; ++i)
      if (get_f(A[i]) != get_f(B[i]) && col[A[i]] != col[B[i]])
        V[i] = 1, fa[get_f(A[i])] = get_f(B[i]);
    for (int i = 1; i <= m; ++i)
      if (!V[i]) {
        S[i] = 1;
        di[A[i]]--;
        di[B[i]]--;
        ai[A[i]]--;
        ai[B[i]]--;
      }
    for (int i = 1; i <= n; ++i)
      if (di[i] == 1) Q.push(i);
    while (!Q.empty()) {
      int t = Q.front();
      Q.pop();
      for (int i = 0; i < edge[t].size(); ++i)
        if (V[edge[t][i]]) {
          int b = A[edge[t][i]] + B[edge[t][i]] - t;
          if (!di[b]) continue;
          di[t]--;
          di[b]--;
          S[edge[t][i]] = ai[t];
          ai[b] -= ai[t];
          ai[t] = 0;
          if (!di[b] && ai[b]) {
            puts("NO");
            exit(0);
          }
          if (di[b] == 1) Q.push(b);
        }
    }
    puts("YES");
    for (int i = 1; i <= m; ++i) printf("%lld\n", S[i]);
  }
}
