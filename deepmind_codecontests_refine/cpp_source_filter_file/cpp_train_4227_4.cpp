#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
void kill() {
  puts("NO");
  exit(0);
}
int N;
int A[2], B[2];
int P[MAXN];
vector<int> adj[MAXN];
int sz[MAXN];
int main() {
  scanf("%d", &N);
  for (int i = 0; i < 2; i++) {
    scanf("%d %d", &A[i], &B[i]);
    A[i]--;
    B[i]--;
  }
  for (int i = 1; i < N; i++) {
    scanf("%d", &P[i]);
    P[i]--;
    adj[P[i]].push_back(i);
  }
  for (int i = N - 1; i >= 0; i--) {
    sz[i] = adj[i].empty();
    for (int j : adj[i]) {
      sz[i] += sz[j];
    }
  }
  if (sz[0] % 2) {
    kill();
  }
  for (int c = 0; c < 2; c++) {
    vector<int> vsz;
    for (int v = A[c]; v; v = P[v]) {
      int p = P[v];
      for (int w : adj[p]) {
        if (w != v && w != B[c]) {
          vsz.push_back(sz[w]);
        }
      }
    }
    for (int v = B[c]; v; v = P[v]) {
      int p = P[v];
      for (int w : adj[p]) {
        if (w != v && w != A[c]) {
          vsz.push_back(sz[w]);
        }
      }
    }
    bitset<MAXN> b;
    b[0] = true;
    for (int s : vsz) {
      b |= (b << s);
    }
    if (!b[sz[0] / 2 - 1]) {
      kill();
    }
  }
  puts("YES");
}
