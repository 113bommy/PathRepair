#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
const int inf = 50000000;
const int maxn = 100010;
pair<long long, int> arr[maxn];
int part[maxn], n;
long long h;
int main() {
  int i, j;
  long long mn, mx, ans, temp;
  scanf("%d%lld", &n, &h);
  for (i = 1; i <= n; i++) {
    scanf("%lld", &arr[i].first);
    arr[i].second = i;
    part[i] = 1;
  }
  sort(arr + 1, arr + n + 1);
  mn = arr[1].first + arr[2].first;
  mx = arr[n].first + arr[n - 1].first;
  ans = mx - mn;
  mn = arr[1].first + arr[2].first + h;
  mx = arr[n].first + arr[1].first + h;
  if (n >= 3) mn = min(mn, arr[2].first + arr[3].first);
  temp = mx - mn;
  if (temp < ans) {
    ans = temp;
    part[arr[1].second] = 2;
  }
  printf("%lld\n", ans);
  for (i = 1; i <= n; i++) printf("%d ", part[i]);
  printf("\n");
  return 0;
}
