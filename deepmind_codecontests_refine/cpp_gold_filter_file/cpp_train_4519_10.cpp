#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 30;
const int MAX_V = 2020;
long long G[MAX_V][MAX_V];
int N, K, C;
bool iscmp;
long long sum;
long long chk1(int s, int& pair) {
  int cnt = 0;
  int idx = 0;
  for (int i = 0; i < N; i++) {
    if (i == s) continue;
    if (G[i][s] >= 0) {
      cnt++;
      idx = i;
    }
  }
  if (cnt != 1) return 0;
  pair++;
  return G[idx][s];
}
long long chk2(int s, int& pair) {
  vector<int> v;
  for (int i = 0; i < N; i++) {
    if (i == s) continue;
    if (G[i][s] >= 0) v.push_back(i);
  }
  long long cost = 0;
  for (int i = 0; i < (int)(v).size(); i++) {
    for (int j = i + 1; j <= (int)(v).size() - 1; j++) {
      cost += G[v[i]][s] + G[v[j]][s];
      pair++;
    }
  }
  return cost;
}
void solve() {
  long long cost = 0;
  if (K >= 3) {
    cost = iscmp ? 2 * sum / N : 0;
  } else {
    int pair = 0;
    for (int i = 0; i < N; i++) {
      if (K == 1) {
        cost += chk1(i, pair);
      } else if (K == 2) {
        cost += chk2(i, pair);
      }
    }
    cost = cost / pair;
  }
  printf("%I64d\n", cost);
}
void coding() {
  while (scanf("%d%d", &N, &K) != EOF) {
    iscmp = true;
    sum = 0;
    for (int i = 0; i < N - 1; i++) {
      for (int j = i + 1; j <= N - 1; j++) {
        scanf("%d", &C);
        G[i][j] = G[j][i] = C;
        sum += C;
        if (C == -1) iscmp = false;
      }
    }
    solve();
  }
}
int main() { coding(); }
