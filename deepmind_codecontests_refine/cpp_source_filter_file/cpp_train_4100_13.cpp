#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:1024000000,1024000000")
const int MAXN = 100109;
const int MAXM = 604000;
const int INF = 0x3f3f3f3f;
const int mod = 258280327;
struct node {
  long long k, a;
  bool operator<(const node &x) const { return k > x.k; }
} x[MAXN];
long long a[66666];
int main() {
  int n;
  a[0] = 1;
  for (int i = 1; a[i - 1] <= 1e9; i++) a[i] = a[i - 1] * 4;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i].k >> x[i].a;
  }
  sort(x, x + n);
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    int l = lower_bound(a, a + 16, x[i].a) - a;
    ans = max(ans, x[i].k + l);
  }
  cout << ans << endl;
  return 0;
}
