#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e6 + 5;
const int MOD = 1e9 + 7;
const int CM = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;
template <typename T>
T MAX(T a, T b) {
  return a > b ? a : b;
}
template <typename T>
T MIN(T a, T b) {
  return a > b ? b : a;
}
template <typename T>
T GCD(T a, T b) {
  return b == 0 ? a : GCD(b, a % b);
}
template <typename T>
T LCM(T a, T b) {
  return a / GCD(a, b) * b;
}
template <typename T>
T ABS(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
T ADD(T a, T b, T MOD) {
  return (a + b) % MOD;
}
template <typename T>
T DEL(T a, T b, T MOD) {
  return ((a - b) % MOD + MOD) % MOD;
}
template <typename T>
T getmod(T a, T mod) {
  return (a % mod + mod) % mod;
}
template <typename T>
void debug(T a, char x) {
  return;
}
int rand(int a, int b) { return rand() % (b - a + 1) + a; }
int a[N];
struct Node {
  int i, j, x;
};
void solve(int kase) {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  int sum = accumulate(a + 1, a + n + 1, 0);
  if (sum % n) {
    printf("-1\n");
    return;
  }
  int ave = sum / n;
  std::vector<Node> ans;
  for (int i = 2; i <= n; i++) {
    int up = (a[i] + i - 1) / i * i;
    ans.push_back({1, i, (up - a[i])});
    a[1] -= up - a[i];
    a[i] = up;
    ans.push_back({i, 1, up / i});
    a[1] += up;
    a[i] = 0;
  }
  for (int i = 2; i <= n; i++) {
    ans.push_back({1, i, ave});
    a[1] -= ave;
    a[i] += ave;
  }
  printf("%lu\n", ans.size());
  for (int i = 0; i < ans.size(); i++)
    printf("%d %d %d\n", ans[i].i, ans[i].j, ans[i].x);
}
const bool DUO = 1;
void TIME() {
  clock_t start, finish;
  double totaltime;
  start = clock();
  if (DUO) {
    int Kase = 0;
    cin >> Kase;
    for (int kase = 1; kase <= Kase; kase++) solve(kase);
  } else
    solve(1);
  finish = clock();
  totaltime = (double)(finish - start) / CLOCKS_PER_SEC;
  printf("\nTime:%lfms\n", totaltime * 1000);
}
int main() {
  if (DUO) {
    int Kase = 0;
    cin >> Kase;
    for (int kase = 1; kase <= Kase; kase++) solve(kase);
  } else
    solve(1);
  return 0;
}
