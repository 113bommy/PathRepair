#include <bits/stdc++.h>
using namespace std;
bool debug = 1;
int n, m, k;
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
long long ln, lk, lm;
int a[100005];
int main() {
  scanf("%d", &n);
  for (int(i) = 0; (i) < (int)(n); (i)++) {
    scanf("%d", a + i);
  }
  sort(a, a + n);
  vector<int> vp;
  for (int i = n - 1; i >= 1;) {
    if (a[i] == a[i - 1] || a[i] - 1 == a[i - 1]) {
      vp.push_back(a[i - 1]);
      i -= 2;
    } else
      i--;
  }
  long long ans = 0;
  for (int i = 0; i + 1 < vp.size(); i += 2) {
    ans += (long long)vp[i] * vp[i + 1];
  }
  printf("%lld\n", ans);
}
