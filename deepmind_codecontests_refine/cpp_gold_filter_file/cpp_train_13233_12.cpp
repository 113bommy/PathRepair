#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int NN = 1e6 + 5;
struct node {
  long long num;
  long long wei;
} a[N];
bool anss[NN];
bool cmp(node a, node b) { return a.num < b.num; }
long long qian[N];
int main() {
  long long n;
  scanf("%lld", &n);
  memset(qian, 0, sizeof(qian));
  for (int i = 1; i <= n; ++i) {
    scanf("%lld", &a[i].num);
    a[i].wei = i;
  }
  sort(a + 1, a + 1 + n, cmp);
  for (int i = 1; i <= n; ++i) {
    qian[i] = qian[i - 1] + a[i].num;
  }
  memset(anss, 0, sizeof(anss));
  long long ans = 0;
  for (int i = 1; i <= n - 1; ++i) {
    long long now = a[i].num;
    if ((qian[n] - now) == 2 * a[n].num) {
      anss[a[i].wei] = 1;
      ans++;
    }
  }
  if (a[n - 1].num == qian[n - 2]) {
    anss[a[n].wei] = 1;
    ans++;
  }
  printf("%lld\n", ans);
  for (int i = 1; i < NN; ++i)
    if (anss[i]) printf("%lld ", i);
}
