#include <bits/stdc++.h>
using namespace std;
void deba(int* a, int n) {
  cerr << "| ";
  for (int i = 0; i < (n); i++) cerr << a[i] << " ";
  cerr << "|" << endl;
}
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }
const int INF = 1 << 30;
const int N = 500000;
int a[102];
int dp[N + 5];
int main() {
  int n, d;
  scanf("%d %d", &n, &d);
  ;
  for (int i = 0; i < (n); i++) scanf("%d", &a[i]);
  ;
  dp[0] = 1;
  for (int i = 0; i < (n); i++)
    for (int j = (N); j >= (0); j--)
      if (dp[j] && j + a[i] <= N) dp[j + a[i]] = 1;
  int p = 0;
  int day = 0;
  while (1) {
    int oldp = p;
    for (int i = (oldp + 1); i <= (min(oldp + d, N)); i++) {
      if (dp[i]) p = i;
    }
    if (p == oldp) break;
    day++;
  }
  cout << p << " " << day << endl;
  return 0;
}
