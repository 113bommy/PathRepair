#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int IT_MAX = 1 << 17;
const long long MOD = 1000000009;
const int INF = 1034567890;
const long long LL_INF = 1234567890123456789ll;
const double PI = acos(-1);
const long double ERR = 1E-13;
vector<int> son[100050];
int sz[100050];
int lr[100050][2];
long double del[100050];
int lr_num = 0;
void DFS1(int n) {
  lr[n][0] = ++lr_num;
  sz[n] = 1;
  for (auto it : son[n]) {
    DFS1(it);
    sz[n] += sz[it];
  }
  lr[n][1] = lr_num;
}
inline void update(int p1, int p2, long double v) {
  del[p1] += v;
  del[p2 + 1] -= v;
}
void DFS2(int n) {
  update(lr[n][0], lr[n][1], 1);
  if (son[n].empty()) return;
  int sum = 0;
  for (auto it : son[n]) sum += sz[it];
  for (auto it : son[n]) update(lr[it][0], lr[it][1], (sum - sz[it]) * 1.0 / 2);
  for (auto it : son[n]) DFS2(it);
}
int main() {
  int N, t, i;
  scanf("%d", &N);
  for (i = 2; i <= N; i++) {
    scanf("%d", &t);
    son[t].push_back(i);
  }
  DFS1(1);
  DFS2(1);
  for (i = 1; i <= N; i++) del[i] += del[i - 1];
  for (i = 1; i <= N; i++) printf("%.10lf ", del[lr[i][0]]);
  return !printf("\n");
}
