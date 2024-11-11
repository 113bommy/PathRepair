#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 20;
long long l[MAXN][2] = {0LL};
long long r[MAXN][2] = {0LL};
int a[MAXN];
int n;
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", &a[i]);
    if (a[i] > 1) l[i][0] = l[i - 1][0] + a[i] - (a[i] & 1);
    l[i][1] = max(l[i][0], l[i - 1][1] + a[i] - (1 - (a[i] & 1)));
  }
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > 1) r[i][0] = r[i + 1][0] + a[i + 1] - (a[i + 1] & 1);
    r[i][1] = max(r[i][0], r[i + 1][1] + a[i + 1] - (1 - (a[i + 1] & 1)));
  }
  long long ret = 0LL;
  for (int i = 0; i < n; i++) {
    ret = max(ret, l[i][0] + r[i][1]);
    ret = max(ret, l[i][1] + r[i][0]);
  }
  cout << ret << endl;
  return 0;
}
