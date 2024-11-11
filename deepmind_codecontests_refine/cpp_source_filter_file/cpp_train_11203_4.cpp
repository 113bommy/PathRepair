#include <bits/stdc++.h>
using namespace std;
const int MM = 1e9 + 7;
const double eps = 1e-8;
const int MAXN = 2e6 + 10;
int n, m;
void prework() {}
void read() {}
int a[MAXN];
pair<int, int> b[MAXN];
void solve(int casi) {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  int tmp = a[0];
  for (int i = 1; i < n; i++) a[i - 1] += a[i];
  a[n] += tmp;
  for (int i = 0; i < n; i++) {
    b[i] = pair<int, int>(a[i], i);
  }
  sort(b, b + n);
  for (int i = 0; i < n; i++) {
    a[b[i].second] = i;
  }
  for (int i = 0; i < n; i++) printf("%d%c", a[i], " \n"[i + 1 == n]);
}
void printans() {}
int main() {
  prework();
  int T = 1;
  for (int i = 1; i <= T; i++) {
    read();
    solve(i);
    printans();
  }
  return 0;
}
