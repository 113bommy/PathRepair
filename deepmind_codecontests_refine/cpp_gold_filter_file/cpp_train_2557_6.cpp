#include <bits/stdc++.h>
using namespace std;
const int size = 1000001;
vector<int> A[size];
int C[size], n, m, k, csize;
bool B[size];
int S[size];
queue<int> q;
inline void bfs(int v) {
  q.push(v);
  B[v] = true;
  int say = 1;
  while (!q.empty()) {
    v = q.front();
    q.pop();
    for (vector<int>::iterator it = A[v].begin(); it != A[v].end(); it++)
      if (!B[*it]) {
        B[*it] = true;
        q.push(*it);
        say++;
      }
  }
  S[say]++;
}
int main() {
  int a, b;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 1; i <= m; i++) {
    scanf("%d %d", &a, &b);
    A[a].push_back(b);
    A[b].push_back(a);
  }
  for (int i = 1; i <= n; i++)
    if (!B[i]) bfs(i);
  for (int i = n; i >= 1; i--)
    if (S[i] >= 1) {
      for (int j = 1; j <= S[i]; j++) C[csize++] = i;
    }
  if (k >= 2) {
    int idx = 1, road = 0, t;
    t = min(C[0], k);
    idx += t;
    for (int i = 1; i < csize; i++) {
      if (idx > i)
        t = min(C[i] - 1, k - 1);
      else {
        idx = i + 1;
        road++;
        t = min(C[i], k - 1);
      }
      idx += t;
      if (idx >= csize) {
        cout << road << endl;
        return 0;
      }
    }
    cout << road << endl;
  } else {
    cout << max(csize - 2, 0) << endl;
  }
  return 0;
}
