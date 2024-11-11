#include <bits/stdc++.h>
#pragma warning(disable : 4996)
#pragma comment(linker, "/STACK:336777216")
using namespace std;
int IT_MAX = 1 << 17;
const long long MOD = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double PI = acos(-1);
const double ERR = 1e-10;
int in[100050];
int val[100050];
int u[100050];
int ans[100050];
int main() {
  int N, i, j;
  scanf("%d", &N);
  for (i = 0; i <= 2 * N - 2; i += 2) scanf("%d", &in[i]);
  in[2 * N] = in[0];
  for (i = 1; i <= 2 * N - 1; i += 2) val[i] = (N - in[i - 1]) - in[i + 1];
  for (i = 0; i < N; i++) u[i] = i * 2 + 1;
  sort(u, u + N, [](int a, int b) { return val[a] < val[b]; });
  for (i = 0; i < N; i++) ans[u[i]] = N - 1 - i;
  for (i = 1; i <= 2 * N - 1; i += 2) printf("%d ", ans[i]);
  return !printf("\n");
}
