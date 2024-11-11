#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
pair<int, int> p[maxn];
int a[maxn];
int b[maxn];
int n, k, cnt;
bool F(int a, int b) { return a > b; }
void solve() {
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  sort(a + 1, a + n + 1);
  sort(b + 1, b + n + 1, F);
  int i = 1, t = 1;
  while (true) {
    if (b[t] + a[i++] >= k) cnt++, t++;
    if (t > n || i > n) break;
  }
  printf("1 %d", cnt);
}
int main() { solve(); }
