#include <bits/stdc++.h>
const int mod = 1000000007;
const int inf = 1000000009;
const long long int INF = 1000000000000000009;
using namespace std;
int T[500001], S[500001], E[500001], V[1000006], L[500006], W[500006],
    D[500001];
vector<int> P[500001];
vector<pair<int, int> > Z[500001];
int A[500001][27];
int numer = 1;
void policz(int n, int p) {
  S[n] = numer;
  V[numer] = n;
  numer++;
  D[n] = 1;
  for (auto v : P[n]) {
    if (v != p) {
      L[v] = L[n] + 1;
      policz(v, n);
      D[n] += D[v];
    }
  }
  numer++;
  E[n] = numer;
}
void dfs(int n, int p, int czy) {
  int maks = -1, big = -1;
  for (auto v : P[n]) {
    if (v != p) {
      if (D[v] > maks) {
        maks = D[v];
        big = v;
      }
    }
  }
  for (auto v : P[n]) {
    if (v != p && v != big) {
      dfs(v, n, 0);
    }
  }
  if (big != -1) dfs(big, n, 1);
  for (auto v : P[n]) {
    if (v != p && v != big) {
      for (int i = S[v]; i < E[v]; i++) {
        int x = V[i];
        A[L[x]][T[x]] ^= 1;
      }
    }
  }
  A[L[n]][T[n]] ^= 1;
  for (auto x : Z[n]) {
    int ile = 0;
    for (int j = 0; j < 26; j++) {
      if (A[x.first][j]) {
        ile++;
      }
    }
    if (ile > 1)
      W[x.second] = 0;
    else
      W[x.second] = 1;
  }
  if (czy == 0) {
    for (int i = S[n]; i < E[n]; i++) {
      int x = V[i];
      A[L[x]][T[x]] ^= 1;
    }
  }
}
int main() {
  int n, q;
  scanf("%d %d", &n, &q);
  for (int i = 2; i <= n; i++) {
    int a;
    scanf("%d", &a);
    P[i].push_back(a);
    P[a].push_back(i);
  }
  L[1] = 1;
  policz(1, 0);
  for (int i = 1; i <= n; i++) {
    char c;
    scanf(" %c", &c);
    T[i] = (int)c - 97;
  }
  for (int i = 1; i <= q; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    Z[a].push_back(make_pair(b, i));
  }
  dfs(1, 0, 1);
  for (int i = 1; i <= q; i++) {
    if (W[i])
      printf("Yes\n");
    else
      printf("No\n");
  }
  return 0;
}
