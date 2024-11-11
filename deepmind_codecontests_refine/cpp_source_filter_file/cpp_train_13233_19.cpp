#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pa;
const int N = 2e5 + 5;
int a[N], maxx = 0, maxx2 = 0;
ll sum = 0;
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
    sum += a[i];
    if (a[i] > maxx) {
      maxx2 = max(maxx2, a[i]);
      maxx = a[i];
    } else
      maxx2 = max(maxx2, a[i]);
  }
  int cnt = 0;
  int ans[N];
  for (int i = 1; i <= n; ++i)
    if (sum - a[i] == 2 * (a[i] == maxx ? maxx2 : maxx)) ans[cnt++] = i;
  printf("%d\n", cnt);
  for (int i = 0; i < cnt; ++i) printf("%d ", ans[i]);
}
