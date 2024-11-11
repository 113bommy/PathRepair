#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int M = 15;
const int INF = 1 << 30;
int n, m[N], p[N];
bool ok[2][N];
bool init() {
  if (!(cin >> n)) return 0;
  for (int i = 1; i <= n; i++) scanf("%d", &m[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &p[i]);
  for (int i = 1; i <= n; i++) ok[0][i] = ok[1][i] = 0;
  return 1;
}
void cal(bool f) {
  long long Min = m[1] - p[1];
  long long tmp = Min;
  for (int i = 2; i <= n; i++) {
    tmp += m[i] - p[i];
    Min = min(Min, tmp);
  }
  long long sum = Min;
  for (int i = 1; i <= n; i++) {
    if (sum >= 0) ok[f][i] = 1;
    sum += (m[i] - p[i]);
  }
}
void solve() {
  cal(0);
  for (int i = 1; i <= n / 2; i++) swap(p[i], p[n - i + 1]);
  for (int i = 2; i <= (n - 1) / 2 + 2; i++) swap(m[i], m[n - i + 2]);
  cal(1);
}
void out() {
  if (ok[1][1]) ok[0][1] = 1;
  for (int i = 2; i <= n; i++)
    if (ok[1][i]) ok[0][n + 2 - i] = 1;
  int res = 0;
  for (int i = 1; i <= n; i++)
    if (ok[0][i]) res++;
  cout << res << endl;
  for (int i = 1; i <= n; i++)
    if (ok[0][i]) printf("%d ", i);
  printf("\n");
}
int main() {
  while (init()) {
    solve();
    out();
  }
}
